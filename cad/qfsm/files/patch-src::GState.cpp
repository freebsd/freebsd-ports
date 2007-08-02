--- src/GState.cpp.orig	2004-11-21 14:48:41.000000000 +0100
+++ src/GState.cpp	2007-08-02 14:07:00.000000000 +0200
@@ -16,7 +16,7 @@
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
 
-#include <math.h>
+#include <cmath>
 
 #include <qpen.h>
 #include <qbrush.h>
@@ -196,9 +196,9 @@
     t->getCPoint2(c2x, c2y);
     info = t->getInfo();
 
-    qDebug("Adresse:     %d", (int)t);
-    qDebug("Start:       %d", (int)t->getStart());
-    qDebug("Ende:        %d", (int)t->getEnd());
+    qDebug("Adresse:     %d", (intptr_t)t);
+    qDebug("Start:       %d", (intptr_t)t->getStart());
+    qDebug("Ende:        %d", (intptr_t)t->getEnd());
     qDebug("Inputs:      %s", info->getInputsStrBin(/*numin*/).latin1());
     qDebug("Outputs:     %s", info->getOutputsStrBin(/*numout*/).latin1());
     qDebug(" ");
@@ -215,9 +215,9 @@
     t->getCPoint2(c2x, c2y);
     info = t->getInfo();
 
-    qDebug("Adresse:     %d", (int)t);
-    qDebug("Start:       %d", (int)t->getStart());
-    qDebug("Ende:        %d", (int)t->getEnd());
+    qDebug("Adresse:     %d", (intptr_t)t);
+    qDebug("Start:       %d", (intptr_t)t->getStart());
+    qDebug("Ende:        %d", (intptr_t)t->getEnd());
     qDebug("Inputs:      %s", info->getInputsStrBin(/*numin*/).latin1());
     qDebug("Outputs:     %s", info->getOutputsStrBin(/*numout*/).latin1());
     qDebug(" ");
