--- rlwrap.h.orig	Sun Aug 12 18:59:20 2001
+++ rlwrap.h	Sun Aug 12 18:58:52 2001
@@ -34,6 +34,10 @@
 #include <getopt.h>
 #endif
 
+#ifdef HAVE_GETOPT_LONG
+#include <getopt.h>
+#endif
+
 #include <string.h>
 #include <errno.h>
 #include <stdarg.h>
