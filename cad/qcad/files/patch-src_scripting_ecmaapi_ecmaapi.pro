--- src/scripting/ecmaapi/ecmaapi.pro.orig	2018-06-19 20:32:20 UTC
+++ src/scripting/ecmaapi/ecmaapi.pro
@@ -4,7 +4,6 @@ CONFIG += plugin
 TARGET = $${RLIBNAME}ecmaapi
 CONFIG -= warn_on
 CONFIG += warn_off
-CONFIG += precompile_header
 PRECOMPILED_HEADER = stable.h
 OTHER_FILES += ecmaapi.dox
 DEFINES += QCADECMAAPI_LIBRARY
@@ -29,4 +28,4 @@ LIBS += \
     -l$${RLIBNAME}spatialindex \
     -l$${RLIBNAME}stemmer \
     -l$${RLIBNAME}zip \
-    -lquazip
+    -lquazip5
