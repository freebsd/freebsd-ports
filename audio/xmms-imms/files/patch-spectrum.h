--- spectrum.h.orig	Sun Jan 25 16:55:21 2004
+++ spectrum.h	Wed Feb 11 17:45:20 2004
@@ -1,7 +1,11 @@
 #ifndef __SPECTRUM_H
 #define __SPECTRUM_H
 
+#if HAVE_STDINT_H
 #include <stdint.h>
+#else
+#include <sys/types.h>
+#endif
 #include <time.h>
 #include <sys/time.h>
 
