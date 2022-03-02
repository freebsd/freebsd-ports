--- jacktrip.pro.orig	2022-01-07 17:52:55 UTC
+++ jacktrip.pro
@@ -5,7 +5,7 @@
 CONFIG += c++11 console
 CONFIG -= app_bundle
 
-CONFIG += qt thread debug_and_release build_all
+CONFIG += qt thread release build_all
 CONFIG(debug, debug|release) {
     TARGET = jacktrip_debug
     application_id = 'org.jacktrip.JackTrip.Devel'
