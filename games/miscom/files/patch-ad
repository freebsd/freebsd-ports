--- level.c	Thu Jan 22 19:30:13 1998
+++ /home/andy/tmp/wrk/level.c	Wed Apr 28 16:37:41 1999
@@ -1,6 +1,10 @@
 #include <stdio.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <ncurses.h>
+#else
 #include <curses.h>
+#endif
 #include "global.h"
 #include "settings.h"
 #include "draw.h"
