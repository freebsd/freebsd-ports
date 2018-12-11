--- datafile.c.orig	2015-12-16 00:46:49 UTC
+++ datafile.c
@@ -23,7 +23,9 @@
 
 #define ISC_BUFFER_USEINLINE
 
+#include <isc/boolean.h>
 #include <isc/buffer.h>
+#include <isc/int.h>
 #include <isc/mem.h>
 
 #include "datafile.h"
