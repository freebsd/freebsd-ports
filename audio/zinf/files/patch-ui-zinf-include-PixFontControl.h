--- ui/zinf/include/PixFontControl.h.orig	Thu Feb 13 21:21:37 2003
+++ ui/zinf/include/PixFontControl.h	Mon Aug 18 17:37:47 2003
@@ -32,7 +32,10 @@
 #pragma warning(disable:4786)
 #endif
 
+#include <inttypes.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #include <string>
 #include <vector>
 
