--- rlwrap.h.orig	Tue Sep 11 06:02:47 2001
+++ rlwrap.h	Mon Mar  4 07:37:19 2002
@@ -36,6 +36,10 @@
 #include <stdlib.h>
 #include <time.h>
 
+#ifdef HAVE_GETOPT_LONG
+#include <getopt.h>
+#endif
+
 #ifdef HAVE_GETOPT_H
 #include <getopt.h>
 #endif
