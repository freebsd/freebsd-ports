--- src/ugene_globals.pri.orig	2016-03-31 12:22:21 UTC
+++ src/ugene_globals.pri
@@ -8,8 +8,8 @@ DEFINES+=UGENE_VER_MAJOR=$${UGENE_VER_MA
 DEFINES+=UGENE_VER_MINOR=$${UGENE_VER_MINOR}
 DEFINES+=UGENE_VER_PATCH=$${UGENE_VER_PATCH}
 
-unix : !macx : INCLUDEPATH-=/usr/include
-unix : !macx : INCLUDEPATH+=/usr/include/qt5 /usr/include
+#unix : !macx : INCLUDEPATH-=/usr/include
+#unix : !macx : INCLUDEPATH+=/usr/include/qt5 /usr/include
 #unix : !macx : INCLUDEPATH =/usr/include/qt5 $$INCLUDEPATH
 
 # NGS package
