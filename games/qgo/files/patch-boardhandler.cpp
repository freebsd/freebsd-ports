--- src/boardhandler.cpp.orig	Sat Feb 22 23:15:42 2003
+++ src/boardhandler.cpp	Sat Feb 22 23:16:09 2003
@@ -2,6 +2,8 @@
 * boardhandler.cpp
 */
 
+#include <qstack.h>
+
 #include "qgo.h"
 #include "boardhandler.h"
 #include "stonehandler.h"
@@ -16,7 +18,6 @@
 #include "setting.h"
 #include <qapplication.h>
 #include <qclipboard.h> 
-#include <qstack.h>
 #include <qlabel.h>
 
 #define MARK_TERRITORY_VISITED     99
