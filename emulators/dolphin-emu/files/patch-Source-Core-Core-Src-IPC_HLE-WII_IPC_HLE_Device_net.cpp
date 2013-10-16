--- Source/Core/Core/Src/IPC_HLE/WII_IPC_HLE_Device_net.cpp.orig	2013-09-18 06:59:39.000000000 +0200
+++ Source/Core/Core/Src/IPC_HLE/WII_IPC_HLE_Device_net.cpp	2013-09-18 15:07:04.000000000 +0200
@@ -23,7 +23,7 @@
 #define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
 #define FREE(x) HeapFree(GetProcessHeap(), 0, (x))
 
-#elif defined(__linux__) or defined(__APPLE__)
+#elif defined(__linux__) or defined(__APPLE__) or defined(__FreeBSD__)
 #include <netdb.h>
 #include <arpa/inet.h>
 #include <sys/types.h>
@@ -1004,7 +1004,7 @@
 				Memory::Write_U32(wii_addr, BufferOut + 4);
 				Memory::Write_U32(wii_addr + sizeof(u32), wii_addr);
 				wii_addr += sizeof(u32);
-				Memory::Write_U32((u32)NULL, wii_addr);
+				Memory::Write_U32((u32)0, wii_addr);
 				wii_addr += sizeof(u32);
 
 				// hardcode to ipv4
@@ -1025,7 +1025,7 @@
 					wii_addr += sizeof(u32);
 				}
 				// NULL terminated list
-				Memory::Write_U32((u32)NULL, wii_addr);
+				Memory::Write_U32((u32)0, wii_addr);
 				wii_addr += sizeof(u32);
 				// The actual IPs
 				for (int i = 0; remoteHost->h_addr_list[i]; i++)
