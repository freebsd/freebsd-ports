--- Include/lnphost.h.orig	2004-11-20 20:22:00 UTC
+++ Include/lnphost.h
@@ -21,6 +21,8 @@
 
 #if defined(LINUX) || defined(linux)
 #define LNP_DEFAULTDEVICE "/dev/ttyS0"
+#elif defined (__FreeBSD__)
+#define LNP_DEFAULTDEVICE "/dev/cuad0"
 #elif defined (__CYGWIN__) || (_WIN32)
 #define LNP_DEFAULTDEVICE "com1"
 #else
