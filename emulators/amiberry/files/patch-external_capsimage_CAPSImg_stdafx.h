--- external/capsimage/CAPSImg/stdafx.h.orig	2026-08-18 12:06:20 UTC
+++ external/capsimage/CAPSImg/stdafx.h
@@ -60,6 +60,12 @@
 #endif
 #endif
 
+#ifdef __FreeBSD__
+#define ftello64 ftello
+#define fseeko64 fseeko
+#define fopen64 fopen
+#endif
+
 #ifndef _WIN32
 
 #define __cdecl
