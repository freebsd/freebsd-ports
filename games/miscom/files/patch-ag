--- unix.c	Sat Mar 15 20:00:27 1997
+++ /home/andy/tmp/wrk/unix.c	Wed Apr 28 16:36:56 1999
@@ -1,5 +1,9 @@
 #include <stdio.h>
+#ifdef __FreeBSD__
+#include <ncurses.h>
+#else
 #include <curses.h>
+#endif
 #include <sys/types.h>
 #include <unistd.h>
 #include <fcntl.h>
