--- include/headers.h.orig	Mon May  9 21:40:53 2005
+++ include/headers.h	Mon May  9 21:41:06 2005
@@ -180,7 +180,7 @@
 // from the gnu archive
 
 #include <iperf-int.h>
-typedef uintmax_t max_size_t;
+typedef uint64_t max_size_t;
 
 /* in case the OS doesn't have these, we provide our own implementations */
 #include "gettimeofday.h"
