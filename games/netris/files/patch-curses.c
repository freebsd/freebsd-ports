--- curses.c.orig	Sat Jun 14 22:11:52 2003
+++ curses.c	Sat Jun 14 22:12:50 2003
@@ -23,6 +23,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <curses.h>
+#include <term.h>
 #include <string.h>
 #include <stdlib.h>
 
