--- PCSCperl.h.orig	Tue May  6 22:23:26 2003
+++ PCSCperl.h	Mon Sep 29 03:06:21 2003
@@ -128,6 +128,16 @@
 
 #endif /* __APPLE__ */
 
+#ifdef __FreeBSD__
+#include <dlfcn.h>
+#include <wintypes.h>
+#include <pcsclite.h>
+#include <stdio.h>
+typedef void *DLL_HANDLE;
+#define LOAD_LIB()	dlopen("libpcsclite.so.0", RTLD_LAZY)
+#define CLOSE_LIB(x)	dlclose(x)
+#define GET_FCT		dlsym
+#endif
 
 /* Definitine fuctions imported from the PCSC library and used by the stub */
 typedef LONG (WINAPI *TSCardEstablishContext) ( DWORD, LPCVOID, LPCVOID, LPSCARDCONTEXT );
