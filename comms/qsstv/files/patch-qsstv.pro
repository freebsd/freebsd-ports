--- qsstv.pro.orig	Tue May  3 23:41:56 2005
+++ qsstv.pro	Mon Jul 18 19:21:35 2005
@@ -14,16 +14,13 @@
 target.path = /usr/local/bin 
 docfiles.files += doc/*.html \
                   doc/*.png 
-docfiles.path = /usr/share/doc/packages/qsstv 
+docfiles.path = ${DOCSDIR}
 INCLUDEPATH += src 
 MOC_DIR = obj 
 UI_DIR = obj 
 OBJECTS_DIR = obj 
-QMAKE_CXXFLAGS_RELEASE += -O2 
-QMAKE_CXXFLAGS_DEBUG += -g3 \
-                        -O0 
-TARGET = ../bin/qsstv 
-DESTDIR = ../bin 
+
+TARGET = qsstv 
 CONFIG += release \
           warn_on \
           qt 
