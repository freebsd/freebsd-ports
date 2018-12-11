--- os.c.orig	2015-12-16 00:46:49 UTC
+++ os.c
@@ -22,6 +22,8 @@
 
 #include <sys/select.h>
 
+#include <isc/boolean.h>
+#include <isc/int.h>
 #include <isc/result.h>
 #include <isc/types.h>
 
