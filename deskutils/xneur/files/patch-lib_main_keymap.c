--- lib/main/keymap.c.orig	2013-10-24 10:26:35 UTC
+++ lib/main/keymap.c
@@ -17,6 +17,7 @@
  *
  */
 
+#include <X11/Xlocale.h>
 #include <X11/XKBlib.h>
 
 #include <stdlib.h>
