--- lib/xml/include/Parse.h.orig	Thu Feb 13 20:47:58 2003
+++ lib/xml/include/Parse.h	Mon Aug 18 17:37:07 2003
@@ -31,7 +31,10 @@
 #pragma warning(disable:4786)
 #endif
 
+#include <inttypes.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #include <string>
 #include <map>
 
