
$FreeBSD$

--- bmore.h.orig	Tue Feb 19 00:41:05 2002
+++ bmore.h	Tue Feb 19 00:41:22 2002
@@ -48,7 +48,7 @@
 #	include <unistd.h>
 #if HAVE_NCURSES_H
 #   include <ncurses.h>
-#	include <ncurses/term.h>
+#	include <term.h>
 #else
 #   include <curses.h>
 #	include <term.h>
