--- source/alleg/blit.c.orig	Mon Jan 17 12:37:21 2005
+++ source/alleg/blit.c	Mon Jan 17 12:38:10 2005
@@ -1,6 +1,8 @@
 #ifdef RAINE_WIN32
 #include <allegro.h>
 #include <winalleg.h>
+#elif defined(RAINE_UNIX)
+#include <sys/time.h>
 #endif
 #include "blit_x2.h"
 #include "eagle.h"
