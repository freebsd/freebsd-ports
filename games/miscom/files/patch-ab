--- draw.c	Sat Mar 15 08:10:31 1997
+++ /home/andy/tmp/wrk/draw.c	Wed Apr 28 16:35:40 1999
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
 #include "unix.h"
