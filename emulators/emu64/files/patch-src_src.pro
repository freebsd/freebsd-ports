--- src/src.pro.orig	2020-11-08 17:21:01 UTC
+++ src/src.pro
@@ -73,7 +73,7 @@ DEFINES += ZIP_SUPPORT=true
 win32 {
     PKGCONFIG += quazip
 } else {
-    LIBS += -lquazip5
+   PKGCONFIG += quazip1-qt5
 }
 
 # Quelltexte
