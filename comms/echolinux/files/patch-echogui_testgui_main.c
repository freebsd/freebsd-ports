--- echogui/testgui_main.c.orig	Sun Feb 15 11:33:04 2004
+++ echogui/testgui_main.c	Fri Jul  2 00:59:18 2004
@@ -16,9 +16,10 @@
 #include <linux/soundcard.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
-#include <forms.h>
+#include <X11/forms.h>
 #include <string.h>
 #include <math.h>
+#include <pthread.h>

 #include "testgui.h"
 #include "serverglobals.h"
