--- src/src.pro.orig	2021-07-08 16:55:15 UTC
+++ src/src.pro
@@ -84,7 +84,7 @@ equals(QT_MAJOR_VERSION, 5) {
     win32 {
         PKGCONFIG += quazip
     } else {
-        LIBS += -lquazip5
+        PKGCONFIG += quazip1-qt5
     }
 
     message("QT5 is active")
