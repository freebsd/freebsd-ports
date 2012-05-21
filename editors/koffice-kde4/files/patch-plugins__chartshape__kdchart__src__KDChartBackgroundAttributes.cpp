--- plugins/chartshape/kdchart/src/KDChartBackgroundAttributes.cpp~	2012-05-21 15:46:35.000000000 -0300
+++ plugins/chartshape/kdchart/src/KDChartBackgroundAttributes.cpp	2012-05-21 15:47:17.000000000 -0300
@@ -22,6 +22,7 @@
 
 #include "KDChartBackgroundAttributes.h"
 #include <QPixmap>
+#include <QVariant>
 
 #include <KDABLibFakes>
 
@@ -150,7 +151,7 @@
 	<< "visible="<<ba.isVisible()
 	<< "brush="<<ba.brush()
 	<< "pixmapmode="<<ba.pixmapMode()
-	<< "pixmap="<<ba.pixmap()
+	<< "pixmap="<<QVariant(ba.pixmap())
 	<< ")";
     return dbg;
 }
