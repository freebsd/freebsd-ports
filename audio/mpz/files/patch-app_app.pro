--- app/app.pro.orig	2021-12-08 11:38:42 UTC
+++ app/app.pro
@@ -171,16 +171,12 @@ contains(DEFINES, MPRIS_ENABLE) {
 
 # Libraries
 INCLUDEPATH += \
-  ../libs/taglib/taglib-1.12/taglib \
-  ../libs/taglib/taglib-1.12/taglib/toolkit \
-  ../libs/taglib/taglib-1.12/taglib/mpeg/id3v2 \
-  ../libs/yaml-cpp/yaml-cpp-0.7.0/include \
+  ${LOCALBASE}/include/taglib \
   ../libs/qtwaitingspinner \
   ../libs/qhotkey/QHotkey-1.5.0
 
 LIBS += \
-  -L../libs/taglib -ltaglib \
-  -L../libs/yaml-cpp -lyaml-cpp \
+  -L${LOCALBASE}/lib -ltag -lyaml-cpp \
   -L../libs/qtwaitingspinner -lqtwaitingspinner \
   -L../libs/qhotkey -lqhotkey
 
@@ -191,5 +187,5 @@ RESOURCES += \
   ../resources.qrc
 
 # make install
-target.path = /usr/bin/
+target.path = $$PREFIX/bin/
 INSTALLS += target
