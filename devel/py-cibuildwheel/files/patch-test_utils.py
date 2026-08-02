--- test/utils.py.orig	2026-08-02 12:34:06.152056000 -0700
+++ test/utils.py
@@ -50,6 +50,8 @@ def get_platform() -> str:
         return platform
     elif sys.platform.startswith("linux"):
         return "linux"
+    elif sys.platform.startswith("freebsd"):
+        return "freebsd"
     elif sys.platform.startswith("darwin"):
         return "macos"
     elif sys.platform.startswith(("win32", "cygwin")):
