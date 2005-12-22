--- ./src/main.c.orig	Wed Dec 21 21:07:21 2005
+++ ./src/main.c	Wed Dec 21 21:07:42 2005
@@ -37,7 +37,7 @@
 #include <sys/msg.h>
 #endif
 
-#if defined(WANT_HAMLIB)
+#if WANT_HAMLIB
 #include <hamlib/rig.h>
 #include "hamlib-utils.h"
 #endif
