--- ui/zinf/include/PixFontControl.h.orig	2003-09-16 17:35:32 UTC
+++ ui/zinf/include/PixFontControl.h
@@ -32,7 +32,10 @@ ________________________________________
 #pragma warning(disable:4786)
 #endif
 
+#include <inttypes.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #include <string>
 #include <vector>
 
