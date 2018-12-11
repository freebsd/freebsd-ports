--- opt.c.orig	2015-12-16 00:46:50 UTC
+++ opt.c
@@ -22,7 +22,9 @@
 
 #include <netinet/in.h>
 
+#include <isc/boolean.h>
 #include <isc/file.h>
+#include <isc/int.h>
 #include <isc/parseint.h>
 #include <isc/result.h>
 
