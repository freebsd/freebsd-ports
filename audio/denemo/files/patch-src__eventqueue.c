--- src/eventqueue.c.orig	2012-09-20 22:44:28.795017000 +0900
+++ src/eventqueue.c	2012-10-05 06:05:30.000000000 +0900
@@ -13,6 +13,7 @@
 
 #include "eventqueue.h"
 #include "midi.h"
+#include "moveviewport.h"
 
 #include <glib.h>
 #include <string.h>
