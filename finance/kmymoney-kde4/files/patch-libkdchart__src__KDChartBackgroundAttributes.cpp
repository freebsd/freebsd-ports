commit 8324cfb9657d8c03f83691402386e8c5bfb29981
Author: Christoph Feck <christoph@maxiom.de>
Date:   Thu Nov 10 12:34:20 2011 +0100

    Fix compile with Qt 4.8
    
    Sideported commits f42a0a3d878afebb298609c9886851858c56cc15 and
    fe74b25bf3b78c42e95569fe467a397876bc9c04 from massif-visualizer

diff --git a/libkdchart/src/KDChartBackgroundAttributes.cpp b/libkdchart/src/KDChartBackgroundAttributes.cpp
index f9f1520..3b86000 100644
--- ./libkdchart/src/KDChartBackgroundAttributes.cpp
+++ ./libkdchart/src/KDChartBackgroundAttributes.cpp
@@ -22,6 +22,7 @@
 
 #include "KDChartBackgroundAttributes.h"
 #include <QPixmap>
+#include <QVariant>
 
 #include <KDABLibFakes>
 
@@ -150,7 +151,7 @@ QDebug operator<<(QDebug dbg, const KDChart::BackgroundAttributes& ba)
 	<< "visible="<<ba.isVisible()
 	<< "brush="<<ba.brush()
 	<< "pixmapmode="<<ba.pixmapMode()
-	<< "pixmap="<<ba.pixmap()
+	<< "pixmap="<<QVariant(ba.pixmap())
 	<< ")";
     return dbg;
 }
