--- tools/json_schema_compiler/model.py.orig	2021-04-14 01:09:38 UTC
+++ tools/json_schema_compiler/model.py
@@ -859,7 +859,7 @@ class Platforms(object):
   CHROMEOS = _PlatformInfo("chromeos")
   CHROMEOS_TOUCH = _PlatformInfo("chromeos_touch")
   LACROS = _PlatformInfo("lacros")
-  LINUX = _PlatformInfo("linux")
+  LINUX = _PlatformInfo("bsd")
   MAC = _PlatformInfo("mac")
   WIN = _PlatformInfo("win")
 
