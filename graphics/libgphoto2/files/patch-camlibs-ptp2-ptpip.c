--- camlibs/ptp2/ptpip.c.orig	Tue Jun 20 04:02:16 2006
+++ camlibs/ptp2/ptpip.c	Sat Jun 24 00:33:29 2006
@@ -31,6 +31,7 @@
 #include <stdio.h>
 #include <time.h>
 #include <errno.h>
+#include <sys/types.h>
 #include <sys/select.h>
 
 #include <sys/socket.h>
