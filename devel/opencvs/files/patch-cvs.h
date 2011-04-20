--- cvs.h.orig	2009-03-25 14:19:20.000000000 -0700
+++ cvs.h	2011-04-18 23:55:35.000000000 -0700
@@ -29,6 +29,10 @@
 
 #include <signal.h>
 
+/* For building on FreeBSD */
+#include <time.h>
+#define	__dead
+
 #include "config.h"
 #include "file.h"
 #include "log.h"
