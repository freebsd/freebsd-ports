--- src/slic3r/Utils/Serial.cpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/Utils/Serial.cpp
@@ -53,7 +53,7 @@
 	#include <sys/select.h>
 #endif
 
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 	#include <termios.h>
 #elif defined __linux__
 	#include <fcntl.h>
@@ -346,7 +346,7 @@ void Serial::set_baud_rate(unsigned baud_rate)
 		ios.c_cc[VTIME] = 1;
 		handle_errno(::ioctl(handle, TCSETS2, &ios));
 
-#elif __OpenBSD__
+#elif defined(__OpenBSD__) || defined(__FreeBSD__)
 		struct termios ios;
 		handle_errno(::tcgetattr(handle, &ios));
 		handle_errno(::cfsetspeed(&ios, baud_rate));
