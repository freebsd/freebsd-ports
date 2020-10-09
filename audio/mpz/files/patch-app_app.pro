--- app/app.pro.orig	2020-10-08 17:36:49 UTC
+++ app/app.pro
@@ -7,8 +7,6 @@ CONFIG += c++11
 
 TARGET = mpz
 
-DEFINES += TAGLIB_STATIC
-
 win32: {
   CONFIG -= debug_and_release
   #CONFIG += static
@@ -134,14 +132,14 @@ FORMS += \
 
 # Libraries
 INCLUDEPATH += \
-  ../libs/taglib/taglib-1.11.1/taglib \
+  ${LOCALBASE}/include/taglib \
   ../libs/taglib/taglib-1.11.1/taglib/toolkit \
   ../libs/yaml-cpp/yaml-cpp-0.6.3/include \
   ../libs/qtwaitingspinner \
   ../libs/qhotkey/QHotkey-1.4.1
 
 LIBS += \
-  -L../libs/taglib -ltaglib \
+  -L${LOCALBASE}/lib -ltag \
   -L../libs/yaml-cpp -lyaml-cpp \
   -L../libs/qtwaitingspinner -lqtwaitingspinner \
   -L../libs/qhotkey -lqhotkey
@@ -165,5 +163,5 @@ RESOURCES += \
   resources/resources.qrc
 
 # make install
-target.path = /usr/bin/
+target.path = $$PREFIX/bin/
 INSTALLS += target
