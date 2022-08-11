--- qsstv.pro.orig	2021-07-31 20:57:03 UTC
+++ qsstv.pro
@@ -517,13 +517,13 @@ contains(QMAKE_HOST.arch, arm.*):{
 
 
 
-dox.path=/usr/share/doc/$$TARGET
+dox.path=%%PREFIX%%/share/doc/$$TARGET
 dox.files= $$PWD/manual/*
 QMAKE_EXTRA_TARGETS   +=   dox
 
 
 isEmpty(PREFIX) {
-        PREFIX = /usr/local
+        PREFIX = %%PREFIX%%
     }
 target.path = $$PREFIX/bin
 
@@ -605,6 +605,6 @@ FORMS   += scope/scopeoffset.ui \
 
 FORMS   += scope/scopeoffset.ui \
                 scope/plotform.ui
-INCLUDEPATH += /usr/include/qwt /usr/include/qt5/qwt
-LIBS += -lqwt-qt5
+INCLUDEPATH += %%PREFIX%%/include/qt5/qwt6
+LIBS += -L%%PREFIX%%/lib/qt5 -lqwt6
 }
