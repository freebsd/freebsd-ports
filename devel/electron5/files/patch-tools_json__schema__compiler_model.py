--- tools/json_schema_compiler/model.py.orig	2019-04-08 08:19:10 UTC
+++ tools/json_schema_compiler/model.py
@@ -602,7 +602,7 @@ class Platforms(object):
   """
   CHROMEOS = _PlatformInfo("chromeos")
   CHROMEOS_TOUCH = _PlatformInfo("chromeos_touch")
-  LINUX = _PlatformInfo("linux")
+  LINUX = _PlatformInfo("bsd")
   MAC = _PlatformInfo("mac")
   WIN = _PlatformInfo("win")
 
