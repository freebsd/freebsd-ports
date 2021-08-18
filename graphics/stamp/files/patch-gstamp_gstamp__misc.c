--- gstamp/gstamp_misc.c.orig	1999-03-11 08:32:44 UTC
+++ gstamp/gstamp_misc.c
@@ -2,6 +2,7 @@
    Eric Werner - 19 FEB 1999 
    ebw@city-net.com
 */
+#include <sys/shm.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
