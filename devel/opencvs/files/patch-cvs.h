--- cvs.h.orig	2015-05-04 11:15:45.000000000 +0200
+++ cvs.h	2016-02-06 23:33:35.522379000 +0100
@@ -29,6 +29,10 @@
 
 #include <signal.h>
 
+/* For building on FreeBSD */
+#include <time.h>
+#define	__dead
+
 #include "config.h"
 #include "file.h"
 #include "log.h"
