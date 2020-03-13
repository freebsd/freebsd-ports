--- tools/json_schema_compiler/model.py.orig	2019-12-12 12:41:31 UTC
+++ tools/json_schema_compiler/model.py
@@ -603,7 +603,7 @@ class Platforms(object):
   """
   CHROMEOS = _PlatformInfo("chromeos")
   CHROMEOS_TOUCH = _PlatformInfo("chromeos_touch")
-  LINUX = _PlatformInfo("linux")
+  LINUX = _PlatformInfo("bsd")
   MAC = _PlatformInfo("mac")
   WIN = _PlatformInfo("win")
 
