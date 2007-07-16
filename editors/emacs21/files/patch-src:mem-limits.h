--- src/mem-limits.h.~1~        Wed Mar  8 12:49:46 2000
+++ src/mem-limits.h    Wed Dec 17 03:15:24 2003
@@ -98,7 +98,7 @@
 static POINTER data_space_start;

 /* Number of bytes of writable memory we can expect to be able to get */
-static unsigned long lim_data;
+static rlim_t lim_data;

 #ifdef NO_LIM_DATA
 static void
