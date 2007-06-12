--- curses.h	Wed Apr  5 11:21:19 1995
+++ curses.h	Mon Jun  4 10:07:51 2007
@@ -7,6 +7,9 @@
  *	kirkenda@cs.pdx.edu
  */
 
+#if TERMIOS
+#include <termios.h>
+#endif
 
 /* This is the header file for a small, fast, fake curses package */
 
