--- scr.c	Sat Jan  2 07:00:11 1999
+++ /home/andy/tmp/wrk/scr.c	Fri May 14 20:28:59 1999
@@ -10,7 +10,11 @@
 # ifdef AMIGA
 #  include <curses210.h>
 # else
-#  include <curses.h>
+#  ifdef __FreeBSD__
+#   include <ncurses.h>
+#  else
+#   include <curses.h>
+#  endif
 # endif
 # include <sys/types.h>
 #endif
