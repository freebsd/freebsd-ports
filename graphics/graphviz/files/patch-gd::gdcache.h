--- gd/gdcache.h.orig	Mon Apr 24 03:04:01 2000
+++ gd/gdcache.h	Thu Nov  8 17:08:56 2001
@@ -40,7 +40,11 @@
 /* header                                                */
 /*********************************************************/
 
+#ifndef __STDC__
 #include <malloc.h>
+#else
+#include <stdlib.h>
+#endif
 #ifndef NULL
 #define NULL (void *)0
 #endif
