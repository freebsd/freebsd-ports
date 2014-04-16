--- qsstv_8.pro.orig	2014-02-28 08:51:21.000000000 -0800
+++ qsstv_8.pro	2014-04-08 02:48:09.000000000 -0700
@@ -420,7 +420,7 @@
 FORMS   += src/scope/scopeoffset.ui \
 				src/scope/plotform.ui
 
- INCLUDEPATH += /usr/include/qwt
+ INCLUDEPATH += $$PREFIX/include/qwt6
  LIBS += -lqwt
 }
 
@@ -430,10 +430,10 @@
 PRE_TARGETDEPS       +=    dox
 message(dox will be generated)
 }
-dox.path=/usr/share/doc/$$TARGET
+dox.path=$$PREFIX/share/doc/$$TARGET
 dox.files= $$PWD/manual/*
 QMAKE_EXTRA_TARGETS   +=   dox
 
-target.path = /usr/bin
+target.path = $$PREFIX/bin
 INSTALLS += target dox
 
