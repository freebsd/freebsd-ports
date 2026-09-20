--- studio/src/camera.cpp.orig	2026-08-26 03:28:33 UTC
+++ studio/src/camera.cpp
@@ -18,6 +18,8 @@ Foundation, Inc., 51 Franklin Street, Fifth Floor, Bos
 */
 #include <cmath>
 
+#include <QQuaternion>
+
 #include "studio/camera.hpp"
 
 namespace Studio {
