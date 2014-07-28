--- ltime.c.org	Mon Oct 27 00:07:24 1997
+++ ltime.c	Wed Feb 18 22:33:56 1998
@@ -2,6 +2,7 @@
 #include <sys/types.h>
 #include <sys/times.h>
 #include <sys/time.h>
+#include <unistd.h>
 
 static void waittcs(unsigned int tcs)
 {
