--- ./lib/isc/include/isc/file.h.orig	2014-01-27 19:58:24.000000000 +0100
+++ ./lib/isc/include/isc/file.h	2014-03-04 17:51:41.000000000 +0100
@@ -25,7 +25,8 @@
 #include <stdio.h>
 
 #include <isc/lang.h>
-#include <isc/stat.h>
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <isc/types.h>
 
 ISC_LANG_BEGINDECLS
