--- tools/json_schema_compiler/model.py.orig	2021-07-15 19:14:06 UTC
+++ tools/json_schema_compiler/model.py
@@ -865,7 +865,7 @@ class Platforms(object):
   """
   CHROMEOS = _PlatformInfo("chromeos")
   LACROS = _PlatformInfo("lacros")
-  LINUX = _PlatformInfo("linux")
+  LINUX = _PlatformInfo("bsd")
   MAC = _PlatformInfo("mac")
   WIN = _PlatformInfo("win")
 
