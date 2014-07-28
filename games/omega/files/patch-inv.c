--- inv.c	Fri Jan  1 03:08:33 1999
+++ /home/andy/tmp/wrk/inv.c	Fri May 14 20:28:52 1999
@@ -8,7 +8,11 @@
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
 #endif
 
