--- src/camera.c.orig	Fri Aug  9 18:19:56 2002
+++ src/camera.c	Tue Oct 26 17:04:03 2004
@@ -19,6 +19,10 @@
 
 #include <stdlib.h>
 #include <stdio.h>
+
+#undef GTK_DISABLE_DEPRECATED
+#warning GTK_DISABLE_DEPRECATED
+
 #include <math.h>
 #include "giram.h"
 #include "utils.h"
