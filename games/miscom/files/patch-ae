--- main.c	Thu Jan 22 19:30:32 1998
+++ /home/andy/tmp/wrk/main.c	Wed Apr 28 16:34:52 1999
@@ -24,7 +24,11 @@
 #include <fcntl.h>
 #include <time.h>
 #include <signal.h>
+#ifdef __FreeBSD__
+#include <ncurses.h>
+#else
 #include <curses.h>
+#endif
 #include "global.h"
 #include "settings.h"
 #include "draw.h"
