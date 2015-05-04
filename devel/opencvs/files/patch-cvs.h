--- cvs.h.orig	2015-05-04 09:15:45 UTC
+++ cvs.h
@@ -29,6 +29,10 @@
 
 #include <signal.h>
 
+/* For building on FreeBSD */
+#include <time.h>
+#define	__dead
+
 #include "config.h"
 #include "file.h"
 #include "log.h"
