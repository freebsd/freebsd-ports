--- gstamp/gstamp_misc.c.orig	2011-03-12 21:33:49.000000000 +0100
+++ gstamp/gstamp_misc.c	2011-03-12 21:34:16.000000000 +0100
@@ -2,6 +2,7 @@
    Eric Werner - 19 FEB 1999 
    ebw@city-net.com
 */
+#include <sys/shm.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
