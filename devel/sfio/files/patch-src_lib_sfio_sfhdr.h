--- src/lib/sfio/sfhdr.h.orig	Thu Nov 11 16:17:56 1999
+++ src/lib/sfio/sfhdr.h	Thu Nov 11 16:19:45 1999
@@ -176,7 +176,7 @@
 #endif
 
 #if !defined(MAXDOUBLE) && _hdr_values
-#include	<values.h>
+#include	<float.h>
 #endif
 
 #if !defined(MAXDOUBLE) && _hdr_floatingpoint
