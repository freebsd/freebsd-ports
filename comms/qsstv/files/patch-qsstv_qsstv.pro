--- qsstv/qsstv.pro.orig	2014-12-06 06:41:00.000000000 -0800
+++ qsstv/qsstv.pro	2014-12-07 16:17:46.000000000 -0800
@@ -420,20 +420,17 @@
 FORMS   += scope/scopeoffset.ui \
 				scope/plotform.ui
 
- INCLUDEPATH += /usr/include/qwt
  LIBS += ../qwt/libqwt.a
 }
 
-CONFIG(debug ,debug|release){
-dox.commands = cd $$PWD/Documentation/manual ;doxygen  manual.doxy;
+with_docs {
+dox.commands = cd Documentation/manual ;doxygen  manual.doxy;
 dox.depends= FORCE
-PRE_TARGETDEPS       +=    dox
 message(dox will be generated)
 }
-dox.path=/usr/share/doc/$$TARGET
-dox.files= $$PWD/manual/*
-QMAKE_EXTRA_TARGETS   +=   dox
+dox.path=$$PREFIX/share/doc/$$TARGET
+dox.files= manual/*
 
-target.path = /usr/bin
+target.path = $$PREFIX/bin
 INSTALLS += target dox
 
