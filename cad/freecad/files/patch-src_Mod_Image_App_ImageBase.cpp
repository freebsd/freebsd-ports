--- ./src/Mod/Image/App/ImageBase.cpp.orig	Sat Feb 24 11:32:27 2007
+++ ./src/Mod/Image/App/ImageBase.cpp	Mon Apr 23 00:11:39 2007
@@ -16,7 +16,11 @@
  ***************************************************************************/
 
 #include "PreCompiled.h"
-#include <malloc.h>
+#if defined(__FreeBSD__)
+# include <stdlib.h>
+#else
+# include <malloc.h>
+#endif
 #include <math.h>
 
 #include "ImageBase.h"
