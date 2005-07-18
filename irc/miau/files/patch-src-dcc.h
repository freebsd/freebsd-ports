--- src/dcc.h.orig	Mon May 16 19:35:50 2005
+++ src/dcc.h	Wed Jul 13 16:54:30 2005
@@ -19,6 +19,9 @@
 
 #include <config.h>
 #include <string.h>
+#include <sys/types.h>
+#include <sys/select.h>
+
 
 #ifdef DCCBOUNCE
 
