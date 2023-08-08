--- texstudio.pro.orig	2022-12-06 17:09:33 UTC
+++ texstudio.pro
@@ -371,10 +371,12 @@ isEmpty(USE_SYSTEM_QUAZIP) {
     }
     !versionGreaterOrEqual($$QT_VERSION, "6.0.0") {
             message(System quazip5)
-            isEmpty(QUAZIP_LIB): QUAZIP_LIB = -lquazip5
+            isEmpty(QUAZIP_LIB): QUAZIP_LIB = -lquazip1-qt5
             isEmpty(QUAZIP_INCLUDE): QUAZIP_INCLUDE = $${PREFIX}/include/quazip5
             INCLUDEPATH += $${QUAZIP_INCLUDE}
             LIBS += $${QUAZIP_LIB}
+	    CONFIG += link_pkgconfig
+	    PKGCONFIG += quazip1-qt5
     }
 }
 
