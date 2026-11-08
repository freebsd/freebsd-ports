--- src/build_tools/util.py.orig	2023-01-23 19:19:19 UTC
+++ src/build_tools/util.py
@@ -51,7 +51,7 @@ def IsLinux():
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 def CaseAwareAbsPath(path: str) -> str:
