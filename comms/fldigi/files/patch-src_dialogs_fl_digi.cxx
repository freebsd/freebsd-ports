--- src/dialogs/fl_digi.cxx.orig	2012-07-07 09:01:19.000000000 -0500
+++ src/dialogs/fl_digi.cxx	2012-07-21 15:24:09.000000000 -0500
@@ -26,6 +26,7 @@
 #include <config.h>
 
 #include <sys/types.h>
+#include <time.h>
 
 #ifdef __WOE32__
 #  ifdef __CYGWIN__
