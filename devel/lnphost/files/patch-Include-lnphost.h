--- Include/lnphost.h.orig	Sat Nov 20 14:22:00 2004
+++ Include/lnphost.h	Thu Sep 13 22:22:20 2007
@@ -21,6 +21,8 @@
 
 #if defined(LINUX) || defined(linux)
 #define LNP_DEFAULTDEVICE "/dev/ttyS0"
+#elif defined (__FreeBSD__)
+#define LNP_DEFAULTDEVICE "/dev/cuad0"
 #elif defined (__CYGWIN__) || (_WIN32)
 #define LNP_DEFAULTDEVICE "com1"
 #else
