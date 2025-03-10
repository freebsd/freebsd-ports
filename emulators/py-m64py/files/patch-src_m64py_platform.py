--- src/m64py/platform.py.orig	2024-12-06 06:23:09 UTC
+++ src/m64py/platform.py
@@ -39,7 +39,7 @@ elif "bsd" in sys.platform:
     CONFIG_DIR = os.environ.get("XDG_CONFIG_HOME") or os.path.join(os.path.expanduser("~"), ".config")
     DEFAULT_DYNLIB = "libmupen64plus.so"
     SEARCH_DIRS = [
-        "/usr/local/lib/mupen64plus",
+        "%%LOCALBASE%%/lib/mupen64plus",
         "."
     ]
 elif sys.platform == "darwin":
