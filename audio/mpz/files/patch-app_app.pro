--- app/app.pro.orig	2021-08-24 08:46:31 UTC
+++ app/app.pro
@@ -154,15 +154,12 @@ FORMS += \
 
 # Libraries
 INCLUDEPATH += \
-  ../libs/taglib/taglib-1.12/taglib \
-  ../libs/taglib/taglib-1.12/taglib/toolkit \
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
 
@@ -185,5 +182,5 @@ RESOURCES += \
   ../resources.qrc
 
 # make install
-target.path = /usr/bin/
+target.path = $$PREFIX/bin/
 INSTALLS += target
