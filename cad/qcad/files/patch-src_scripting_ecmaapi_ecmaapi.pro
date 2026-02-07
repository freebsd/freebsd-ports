--- src/scripting/ecmaapi/ecmaapi.pro.orig	2019-05-01 14:25:33 UTC
+++ src/scripting/ecmaapi/ecmaapi.pro
@@ -4,7 +4,6 @@ CONFIG += plugin
 TARGET = $${RLIBNAME}ecmaapi
 CONFIG -= warn_on
 CONFIG += warn_off
-CONFIG += precompile_header
 PRECOMPILED_HEADER = stable.h
 OTHER_FILES += ecmaapi.dox
 DEFINES += QCADECMAAPI_LIBRARY
