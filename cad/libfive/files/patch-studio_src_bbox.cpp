--- studio/src/bbox.cpp.orig	2026-08-26 03:29:16 UTC
+++ studio/src/bbox.cpp
@@ -18,6 +18,7 @@ Foundation, Inc., 51 Franklin Street, Fifth Floor, Bos
 */
 #include <cmath>
 #include <boost/math/constants/constants.hpp>
+#include <QQuaternion>
 
 #include "studio/bbox.hpp"
 #include "studio/camera.hpp"
