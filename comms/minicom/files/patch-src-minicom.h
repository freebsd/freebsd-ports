--- src/minicom.h.orig	2013-12-08 10:26:03 UTC
+++ src/minicom.h
@@ -35,6 +35,7 @@
 
 #include <time.h>
 #include <stdbool.h>
+#include <limits.h>
 
 #if HAVE_LOCKDEV
 #include <ttylock.h>
