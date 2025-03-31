--- cibuildwheel/architecture.py.orig	2025-03-31 08:32:45 UTC
+++ cibuildwheel/architecture.py
@@ -87,7 +87,11 @@ class Architecture(Enum):
         host_platform: PlatformName = (
             "windows"
             if sys.platform.startswith("win")
-            else ("macos" if sys.platform.startswith("darwin") else "linux")
+            else (
+                "macos" if sys.platform.startswith("darwin") else (
+                    "freebsd" if sys.platform.startswith("freebsd") else "linux"
+                )
+             )
         )
 
         native_machine = platform_module.machine()
