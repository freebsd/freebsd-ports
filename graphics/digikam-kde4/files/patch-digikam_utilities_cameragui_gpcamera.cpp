--- digikam/utilities/cameragui/gpcamera.cpp.orig	2007-09-18 09:23:44.000000000 +0200
+++ digikam/utilities/cameragui/gpcamera.cpp	2007-09-18 09:24:48.000000000 +0200
@@ -22,13 +22,6 @@
  * 
  * ============================================================ */
 
-// C Ansi includes.
-
-extern "C"
-{
-#include <gphoto2.h>
-}
-
 // C++ includes.
 
 #include <cstdio>
@@ -47,6 +40,13 @@
 
 #include <klocale.h>
 
+// C Ansi includes.
+
+extern "C"
+{
+#include <gphoto2.h>
+}
+
 // Local includes.
 
 #include "ddebug.h"
