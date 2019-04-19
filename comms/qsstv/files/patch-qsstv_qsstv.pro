--- qsstv/qsstv.pro.orig	2019-04-18 09:34:09 UTC
+++ qsstv/qsstv.pro
@@ -523,7 +523,7 @@ contains(QMAKE_HOST.arch, arm.*):{
     }
   else {
         message(not arm)
-       CONFIG(debug ,debug|release){
+       CONFIG(dox){
        dox.commands = cd $$PWD/documentation/manual ;doxygen  manual.doxy; cd $$PWD/documentation/api ;doxygen  api.doxy;
        dox.depends= FORCE
        PRE_TARGETDEPS       +=    dox
@@ -535,15 +535,15 @@ contains(QMAKE_HOST.arch, arm.*):{
 
 
 
-dox.path=/usr/share/doc/$$TARGET
-dox.files= $$PWD/manual/*
+dox.path=%%DOCSDIR%%
+dox.files= documentation/manual/*
 QMAKE_EXTRA_TARGETS   +=   dox
 
 
 isEmpty(PREFIX) {
         PREFIX = /usr/local
     }
-target.path = $$PREFIX/bin
+target.path = %%PREFIX%%/bin
 
 shortcutfiles.files =qsstv.desktop
 shortcutfiles.path = $$PREFIX/share/applications/
