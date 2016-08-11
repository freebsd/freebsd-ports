--- source/fbsd_joystick.c.orig	2001-12-10 00:47:38 UTC
+++ source/fbsd_joystick.c
@@ -44,7 +44,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <sys/time.h>
-#include <machine/joystick.h>
+#include <sys/joystick.h>
 
 #include "argv.h"
 #include "global.h"
