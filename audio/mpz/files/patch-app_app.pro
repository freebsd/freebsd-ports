--- app/app.pro.orig	2021-08-16 05:33:03 UTC
+++ app/app.pro
@@ -154,14 +154,14 @@ FORMS += \
 
 # Libraries
 INCLUDEPATH += \
-  ../libs/taglib/taglib-1.12/taglib \
-  ../libs/taglib/taglib-1.12/taglib/toolkit \
+  ${LOCALBASE}/include/taglib \
+  ${LOCALBASE}/include/taglib/toolkit \
   ../libs/yaml-cpp/yaml-cpp-0.6.3/include \
   ../libs/qtwaitingspinner \
   ../libs/qhotkey/QHotkey-1.4.2
 
 LIBS += \
-  -L../libs/taglib -ltaglib \
+  -L${LOCALBASE}/lib -ltag \
   -L../libs/yaml-cpp -lyaml-cpp \
   -L../libs/qtwaitingspinner -lqtwaitingspinner \
   -L../libs/qhotkey -lqhotkey
@@ -185,5 +185,5 @@ RESOURCES += \
   ../resources.qrc
 
 # make install
-target.path = /usr/bin/
+target.path = $$PREFIX/bin/
 INSTALLS += target
