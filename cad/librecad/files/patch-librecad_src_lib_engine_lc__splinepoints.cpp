--- librecad/src/lib/engine/lc_splinepoints.cpp.orig	2020-05-21 10:23:28 UTC
+++ librecad/src/lib/engine/lc_splinepoints.cpp
@@ -22,6 +22,7 @@ Foundation, Inc., 51 Franklin Street, Fifth Floor, Bos
 **********************************************************************/
 
 #include <QPolygonF>
+#include <QPainterPath>
 #include "lc_splinepoints.h"
 
 #include "rs_circle.h"
