--- studio/include/studio/camera.hpp.orig	2026-08-26 03:38:22 UTC
+++ studio/include/studio/camera.hpp
@@ -21,6 +21,7 @@ Foundation, Inc., 51 Franklin Street, Fifth Floor, Bos
 #include <QMatrix4x4>
 #include <QObject>
 #include <QPropertyAnimation>
+#include <QQuaternion>
 
 namespace Studio {
 class Camera : public QObject
