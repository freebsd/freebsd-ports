--- src/interface.c.orig	Mon Mar 25 00:02:08 2002
+++ src/interface.c	Wed Mar 27 02:03:28 2002
@@ -23,8 +23,10 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <sys/types.h>
+#include <sys/time.h>
+#include <unistd.h>
 #include <gtkgl/gtkglarea.h>
-#include <sys/select.h>
 
 #include "global.h"
 #include "interface.h"
