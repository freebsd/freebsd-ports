--- src/noderesults.cpp.orig	Sat Feb 22 23:18:46 2003
+++ src/noderesults.cpp	Sat Feb 22 23:19:13 2003
@@ -2,10 +2,11 @@
 * noderesults.cpp
 */
 
+#include <qstack.h>
+
 #include "noderesults.h"
 #include "move.h"
 #include "icons.h"
-#include <qstack.h>
 #include <qpixmap.h>
 #include <qiconview.h>
 #include <qpushbutton.h>
