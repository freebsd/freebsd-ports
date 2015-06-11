--- fracplanet.pro.orig	2015-06-11 10:31:19 UTC
+++ fracplanet.pro
@@ -1,7 +1,7 @@
 TARGET = fracplanet
 TEMPLATE = app
 
-CONFIG+= qt stl precompile_header exceptions release  # debug/release
+CONFIG+= qt stl exceptions release  # debug/release
 QT += opengl
 
 PRECOMPILED_HEADER = precompiled.h
