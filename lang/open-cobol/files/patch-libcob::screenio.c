--- libcob/screenio.c.orig	Fri Mar 12 13:41:58 2004
+++ libcob/screenio.c	Wed Nov 24 02:43:30 2004
@@ -19,6 +19,7 @@
 
 #include "config.h"
 
+#include <stdio.h>
 #include <string.h>
 
 #if HAVE_NCURSES_H
