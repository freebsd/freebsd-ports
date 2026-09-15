-- Recognize FreeBSD as a native platform and route it through the Linux
-- platform module, since cibuildwheel does not ship a dedicated FreeBSD backend.
-- This is enough for unit tests and --print-build-identifiers usage.

--- cibuildwheel/platforms/__init__.py.orig	2026-09-14 15:11:41 UTC
+++ cibuildwheel/platforms/__init__.py
@@ -37,12 +37,15 @@ ALL_PLATFORM_MODULES: Final[dict[PlatformName, Platfor
     "pyodide": pyodide,
     "android": android,
     "ios": ios,
+    "freebsd": linux,
 }


 def native_platform() -> PlatformName:
     if sys.platform.startswith("linux"):
         return "linux"
+    elif sys.platform.startswith("freebsd"):
+        return "freebsd"
     elif sys.platform == "darwin":
         return "macos"
     elif sys.platform == "win32":
