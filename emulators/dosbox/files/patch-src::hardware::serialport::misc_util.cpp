--- src/hardware/serialport/misc_util.cpp.orig
+++ src/hardware/serialport/misc_util.cpp
@@ -6,7 +6,7 @@
 // C++ SDLnet wrapper
 
 // Socket inheritance
-#if defined LINUX || defined OS2
+#if defined LINUX || defined OS2 || defined FREEBSD
 #define CAPWORD (NETWRAPPER_TCP|NETWRAPPER_TCP_NATIVESOCKET)
 #ifdef OS2
 typedef int     socklen_t;
