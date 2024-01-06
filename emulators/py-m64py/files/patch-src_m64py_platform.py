--- src/m64py/platform.py.orig	2023-12-26 23:01:25 UTC
+++ src/m64py/platform.py
@@ -31,6 +31,15 @@ if sys.platform.startswith("linux"):
         "/usr/lib/i386-linux-gnu/mupen64plus",
         "."
     ]
+elif sys.platform.startswith("freebsd"):
+    DLL_EXT = ".so"
+    DLL_FILTER = ""
+    DEFAULT_DYNLIB = "libmupen64plus.so.2"
+    SEARCH_DIRS = [
+        "%%LOCALBASE%%/lib/",
+        "%%LOCALBASE%%/lib/mupen64plus/",
+        "."
+    ]
 elif sys.platform.startswith("openbsd"):
     DLL_EXT = ".so"
     DLL_FILTER = ""
