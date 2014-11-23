--- qsstv/qsstv.pro.orig	2014-10-11 09:38:33.000000000 -0700
+++ qsstv/qsstv.pro	2014-11-22 19:05:11.000000000 -0800
@@ -420,7 +420,6 @@
 FORMS   += scope/scopeoffset.ui \
 				scope/plotform.ui
 
- INCLUDEPATH += /usr/include/qwt
  LIBS += ../qwt/libqwt.a
 }
 
@@ -430,10 +429,10 @@
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
 
