--- src/arch/InputHandler/InputHandler_Linux_Joystick.cpp.orig	2008-01-30 13:54:28.000000000 +0200
+++ src/arch/InputHandler/InputHandler_Linux_Joystick.cpp	2008-01-30 13:55:14.000000000 +0200
@@ -9,6 +9,8 @@
 
 #include <errno.h>
 #include <sys/types.h>
+#include <sys/ioctl.h>
+#include <sys/stat.h>
 #include <linux/joystick.h>
 
 #include <set>
