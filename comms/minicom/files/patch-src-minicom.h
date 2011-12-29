--- src/minicom.h.orig	2011-09-30 09:57:22.000000000 +0200
+++ src/minicom.h	2011-12-28 16:12:54.000000000 +0100
@@ -35,6 +35,7 @@
 
 #include <time.h>
 #include <stdbool.h>
+#include <limits.h>
 
 #if HAVE_LOCKDEV
 #include <ttylock.h>
