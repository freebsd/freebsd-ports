--- libcob/screenio.c.orig	Thu Apr  3 06:02:51 2003
+++ libcob/screenio.c	Tue Apr 29 04:09:44 2003
@@ -19,6 +19,7 @@
 
 #include "config.h"
 
+#include <sys/types.h>
 #include <string.h>
 #if HAVE_CURSES_H
 #include <curses.h>
