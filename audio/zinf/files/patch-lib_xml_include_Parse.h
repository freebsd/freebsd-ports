--- lib/xml/include/Parse.h.orig	2003-09-16 17:35:11 UTC
+++ lib/xml/include/Parse.h
@@ -31,7 +31,10 @@ ________________________________________
 #pragma warning(disable:4786)
 #endif
 
+#include <inttypes.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #include <string>
 #include <map>
 
