--- fire.c	Sat Mar 15 23:42:10 1997
+++ /home/andy/tmp/wrk/fire.c	Wed Apr 28 16:36:14 1999
@@ -4,7 +4,11 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
+#ifdef __FreeBSD__
+#include <ncurses.h>
+#else
 #include <curses.h>
+#endif
 
 #include "global.h"
 #include "settings.h"
