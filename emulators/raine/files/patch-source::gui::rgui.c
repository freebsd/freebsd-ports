--- source/gui/rgui.c.orig	Mon Jan 17 12:07:21 2005
+++ source/gui/rgui.c	Mon Jan 17 12:23:46 2005
@@ -9,6 +9,10 @@
 #include <winalleg.h>
 #endif

+#ifdef RAINE_UNIX
+#include <sys/time.h>
+#endif
+
 #include "raine.h"
 #include "rgui.h"
 #include "rguiproc.h"
@@ -1507,6 +1511,10 @@
 void dialog_oxygen(void)
 {

+#ifdef RAINE_UNIX
+  struct timeval timeout;
+#endif
+
 #ifdef BUFFER_GUI
    static int z,z1,z2,z3;
    int ta;
@@ -1560,7 +1568,6 @@
   // its sleep function has a 1ms resolution instead of 1us. Too bad...
    Sleep(1000/60);
 #elif defined(RAINE_UNIX)
-  struct timeval timeout;
   timeout.tv_sec = 0;
   timeout.tv_usec = 1000000/60;
   select(0, NULL, NULL, NULL, &timeout);
