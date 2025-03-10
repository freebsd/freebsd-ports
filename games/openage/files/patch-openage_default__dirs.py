--- openage/default_dirs.py.orig	2024-11-26 15:15:38 UTC
+++ openage/default_dirs.py
@@ -33,6 +33,14 @@ LINUX_DIRS = {
     "runtime_dir": ("XDG_RUNTIME_DIR", ("/run/user/$UID")),
 }
 
+FREEBSD_DIRS = {
+    "config_home": ("XDG_CONFIG_HOME", ("{HOME}/.config", {"HOME"})),
+    "data_home": ("XDG_DATA_HOME", ("{HOME}/.local/share", {"HOME"})),
+    "data_dirs": ("XDG_DATA_DIRS", ("/usr/local/share/", {})),
+    "config_dirs": ("XDG_CONFIG_DIRS", ("/etc/xdg", {})),
+    "cache_home": ("XDG_CACHE_HOME", ("{HOME}/.cache", {"HOME"})),
+    "runtime_dir": ("XDG_RUNTIME_DIR", ("/run/user/$UID")),
+}
 
 # Windows-specific paths
 WINDOWS_DIRS = {
@@ -59,6 +67,9 @@ def get_dir(which):
 
     elif sys.platform.startswith("win32"):
         platform_table = WINDOWS_DIRS
+
+    elif sys.platform.startswith("freebsd"):
+    	platform_table = FREEBSD_DIRS
 
     else:
         raise RuntimeError(f"unsupported platform: '{sys.platform}'")
