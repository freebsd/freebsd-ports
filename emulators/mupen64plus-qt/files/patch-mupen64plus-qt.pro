--- mupen64plus-qt.pro.orig	2020-11-08 17:31:05 UTC
+++ mupen64plus-qt.pro
@@ -86,7 +86,8 @@ win32|macx|linux_quazip_static {
                 LIBS += -lquazip5
             }
         } else {
-            LIBS += -lquazip5
+            CONFIG += link_pkgconfig
+            PKGCONFIG += quazip1-qt5
         }
     }
 }
