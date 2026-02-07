--- fixstr.c	Sat Aug  8 13:48:23 1998
+++ /home/andy/tmp/wrk/fixstr.c	Fri May 14 20:37:59 1999
@@ -15,7 +15,9 @@
 Thus it can be broken. */
 
 #include <stdio.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
+#endif
 
 #define TMPFILE "fixtmp.c"
 
