--- cxterm/scrollbar.c.orig	2007-11-22 14:47:15.000000000 +0100
+++ cxterm/scrollbar.c	2007-11-22 14:47:49.000000000 +0100
@@ -37,6 +37,7 @@
 #include "ptyx.h"		/* gets Xt headers, too */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include <X11/Xatom.h>
 
@@ -323,7 +324,6 @@
 	register TScreen *screen = &xw->screen;
 	register int border = 2 * screen->border;
 	register int i;
-	Char *realloc(), *calloc();
 
 	if(screen->scrollbar)
 		return;
