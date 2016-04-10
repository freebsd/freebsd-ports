--- qsstv/qsstv.pro.orig	2016-04-08 23:08:29 UTC
+++ qsstv/qsstv.pro
@@ -15,7 +15,7 @@ QMAKE_CXXFLAGS_RELEASE += -O3
 
 TARGET = qsstv
 TEMPLATE = app
-INCLUDEPATH += config utils sound widgets dsp dispatch logbook mainwidgets rig sstv videocapt drmrx drmtx xmlrpc  /usr/include/openjpeg-2.1
+INCLUDEPATH += config utils sound widgets dsp dispatch logbook mainwidgets rig sstv videocapt drmrx drmtx xmlrpc  %%LOCALBASE%%/include/openjpeg-2.1
 
 
 SOURCES += main.cpp\
@@ -515,8 +515,8 @@ PRE_TARGETDEPS       +=    dox
 message(dox will be generated)
 }
 
-dox.path=/usr/share/doc/$$TARGET
-dox.files= $$PWD/manual/*
+dox.path=%%DOCSDIR%%
+dox.files= documentation/manual/*
 QMAKE_EXTRA_TARGETS   +=   dox
 
 
@@ -524,5 +524,5 @@ QMAKE_EXTRA_TARGETS   +=   dox
 RESOURCES += \
     qsstv.qrc
 
-target.path = /usr/bin
+target.path = %%PREFIX%%/bin
 INSTALLS += target dox
