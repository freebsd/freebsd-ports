--- src/global.h.orig   Thu Aug  7 12:54:31 2003
+++ src/global.h        Thu Aug  7 12:54:46 2003
@@ -26,7 +26,7 @@
 //#endif
 #define _(String) gettext (String)
 #define gettext_noop(String) (String)
-
+#include <assert.h>
 #include "graphdev.h"
 #include "hzdecoder.h"
 //class Console;
