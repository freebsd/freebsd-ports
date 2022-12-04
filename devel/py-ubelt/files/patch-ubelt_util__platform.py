--- ubelt/util_platform.py.orig	2022-12-03 05:15:05 UTC
+++ ubelt/util_platform.py
@@ -42,7 +42,7 @@ from os.path import exists, join, isdir, expanduser, n
 
 
 __all__ = [
-    'WIN32', 'LINUX', 'DARWIN', 'POSIX',
+    'WIN32', 'FREEBSD', 'LINUX', 'DARWIN', 'POSIX',
     'find_exe', 'find_path',
     'ensure_app_cache_dir', 'ensure_app_config_dir', 'ensure_app_data_dir',
     'get_app_cache_dir', 'get_app_config_dir', 'get_app_data_dir',
@@ -67,6 +67,8 @@ def platform_data_dir():
     """
     if POSIX:  # nocover
         dpath_ = os.environ.get('XDG_DATA_HOME', '~/.local/share')
+    elif FREEBSD:  # nocover
+        dpath_ = os.environ.get('XDG_DATA_HOME', '~/.local/share')
     elif DARWIN:  # nocover
         dpath_  = '~/Library/Application Support'
     elif WIN32:  # nocover
@@ -86,6 +88,8 @@ def platform_config_dir():
         str : path to the cache dir used by the current operating system
     """
     if POSIX:  # nocover
+        dpath_ = os.environ.get('XDG_CONFIG_HOME', '~/.config')
+    elif FREEBSD:  # nocover
         dpath_ = os.environ.get('XDG_CONFIG_HOME', '~/.config')
     elif DARWIN:  # nocover
         dpath_  = '~/Library/Application Support'
