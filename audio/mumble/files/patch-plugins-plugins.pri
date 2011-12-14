$FreeBSD$

Disable debug; runs into cryptic errors on 9+/amd64

--- plugins/plugins.pri.orig	2011-02-19 21:35:16.000000000 +0000
+++ plugins/plugins.pri	2011-11-28 20:27:31.374646598 +0000
@@ -1,16 +1,11 @@
 include(../compiler.pri)
 
 TEMPLATE	= lib
-CONFIG		+= plugin debug_and_release warn_on
+CONFIG		+= plugin warn_on
 CONFIG		-= qt
 DIST		*= mumble_plugin.h
 
-CONFIG(debug, debug|release) {
-  CONFIG += console
-  DESTDIR       = ../../debug/plugins
-}
-
-CONFIG(release, debug|release) {
+CONFIG(release, release) {
   DESTDIR       = ../../release/plugins
 }
 
