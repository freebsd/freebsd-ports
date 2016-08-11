Disable debug; runs into cryptic errors on 9+/amd64

--- plugins/plugins.pri.orig	2014-08-08 15:51:59 UTC
+++ plugins/plugins.pri
@@ -1,7 +1,7 @@
 include(../compiler.pri)
 
 TEMPLATE	= lib
-CONFIG		+= plugin debug_and_release warn_on
+CONFIG		+= plugin warn_on
 CONFIG		-= qt
 DIST		*= mumble_plugin.h
 
@@ -10,12 +10,7 @@ CONFIG(static) {
 	CONFIG += qt_dynamic_lookup
 }
 
-CONFIG(debug, debug|release) {
-  CONFIG += console
-  DESTDIR       = ../../debug/plugins
-}
-
-CONFIG(release, debug|release) {
+CONFIG(release, release) {
   DESTDIR       = ../../release/plugins
 }
 
