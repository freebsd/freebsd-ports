--- file.c	Fri Jan  1 03:08:26 1999
+++ /home/andy/tmp/wrk/file.c	Fri May 14 20:28:46 1999
@@ -9,7 +9,11 @@
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
 # include <unistd.h>
