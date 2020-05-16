--- jacktrip.pro.orig	2020-05-16 21:20:44 UTC
+++ jacktrip.pro
@@ -5,7 +5,7 @@
 CONFIG += c++11 console
 CONFIG -= app_bundle
 
-CONFIG += qt thread debug_and_release build_all
+CONFIG += qt thread release build_all
 CONFIG(debug, debug|release) {
   TARGET = jacktrip_debug
   } else {
@@ -109,7 +109,7 @@ win32 {
 
 DESTDIR = .
 QMAKE_CLEAN += -r ./jacktrip ./jacktrip_debug ./release ./debug
-target.path = /usr/bin
+target.path = $${PREFIX}/bin/
 INSTALLS += target
 
 # for plugins
