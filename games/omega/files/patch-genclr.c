--- genclr.c.orig	Sat Aug  8 21:53:59 1998
+++ genclr.c	Thu Oct 16 20:38:27 2003
@@ -281,16 +281,20 @@
      */
     fp = emitopen (cfile, argv);
     fprintf (fp, "\
+#ifdef __FreeBSD__\n\
+#include <ncurses.h>\n\
+#else\n\
 #include <curses.h>\n\
+#endif\n\
 #include <stdio.h>\n\
 #include <stdlib.h>\n\
-
+\n\
 #include \"%s\"\n\
-
+\n\
 void clrgen_init (void)\n\
 ""{\n\
     if (%d > COLOR_PAIRS - 1) {\n\
-	endwin();
+	endwin();\n\
 	fputs (\"Too many color pairs!\\n\", stderr);\n\
 	exit (1);\n\
     }\n\
