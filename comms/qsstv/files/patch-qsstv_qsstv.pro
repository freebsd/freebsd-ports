--- qsstv/qsstv.pro.orig	2018-06-25 14:41:05 UTC
+++ qsstv/qsstv.pro
@@ -523,8 +523,8 @@ PRE_TARGETDEPS       +=    dox
 message(dox will be generated)
 }
 
-dox.path=/usr/share/doc/$$TARGET
-dox.files= $$PWD/manual/*
+dox.path=%%DOCSDIR%%
+dox.files= documentation/manual/*
 QMAKE_EXTRA_TARGETS   +=   dox
 
 
@@ -532,5 +532,5 @@ QMAKE_EXTRA_TARGETS   +=   dox
 RESOURCES += \
     qsstv.qrc
 
-target.path = /usr/bin
+target.path = %%PREFIX%%/bin
 INSTALLS += target dox
