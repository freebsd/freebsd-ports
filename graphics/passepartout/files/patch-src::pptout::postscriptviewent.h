--- src/pptout/postscriptviewent.h.orig	Thu Dec  4 10:51:01 2003
+++ src/pptout/postscriptviewent.h	Thu Dec  4 10:56:37 2003
@@ -5,6 +5,7 @@
 ///
 #include "viewent.h"
 #include "document/cachedframe.h"
+#include <unistd.h>
 
 class PostscriptViewent : public Viewent {
 protected:
