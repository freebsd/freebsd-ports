--- version.h.orig	Wed Sep 24 20:56:57 2003
+++ version.h	Wed Sep 24 20:58:44 2003
@@ -4,10 +4,12 @@
 #define FUH_VERSION		"0.30"
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
