--- source/gui/rgui.c.orig	Mon Jan 17 12:07:21 2005
+++ source/gui/rgui.c	Mon Jan 17 12:23:46 2005
@@ -9,1 +9,1 @@
 #include <winalleg.h>
 #endif

+#ifdef RAINE_UNIX
+#include <sys/time.h>
+#endif
+
 #include "raine.h"
 #include "rgui.h"
 #include "rguiproc.h"
