--- src/appleseed.studio/python/module.cpp.orig	2019-08-31 15:49:01 UTC
+++ src/appleseed.studio/python/module.cpp
@@ -26,10 +26,12 @@
 // THE SOFTWARE.
 //
 
+// XXX: must be included before Qt headers because of `slot' redefine
+#include "python/pythoninterpreter.h"
+
 // appleseed.studio headers.
 #include "mainwindow/mainwindow.h"
 #include "mainwindow/minimizebutton.h"
-#include "python/pythoninterpreter.h"
 
 // appleseed.foundation headers.
 #include "foundation/core/exceptions/exception.h"
