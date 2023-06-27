--- src/src.pro.orig	2023-06-23 23:22:04 UTC
+++ src/src.pro
@@ -91,7 +91,7 @@ equals(QT_MAJOR_VERSION, 5) {
     win32 {
         PKGCONFIG += quazip
     } else {
-        LIBS += -lquazip5
+        PKGCONFIG += quazip1-qt5
     }
 
     message("QT5 is active")
