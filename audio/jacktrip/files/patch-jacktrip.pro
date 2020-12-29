--- jacktrip.pro.orig	2020-11-15 00:26:30 UTC
+++ jacktrip.pro
@@ -5,7 +5,7 @@
 CONFIG += c++11 console
 CONFIG -= app_bundle
 
-CONFIG += qt thread debug_and_release build_all
+CONFIG += qt thread release build_all
 CONFIG(debug, debug|release) {
   TARGET = jacktrip_debug
   } else {
