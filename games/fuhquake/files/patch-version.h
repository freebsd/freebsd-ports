--- version.h.orig	Wed Jan  7 00:58:18 2004
+++ version.h	Sun Jan 22 22:07:23 2006
@@ -4,10 +4,12 @@
 #define FUH_VERSION		"0.31"
 #define LINUX_VERSION	0.98
 
-#ifdef _WIN32
+#if defined(_WIN32)
 #define QW_PLATFORM	"Win32"
-#else 
+#elif defined(__linux__)
 #define QW_PLATFORM	"Linux"
+#elif defined(__FreeBSD__)
+#define QW_PLATFORM	"FreeBSD"
 #endif
 
 #ifdef GLQUAKE
