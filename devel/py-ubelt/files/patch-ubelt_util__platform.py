--- ubelt/util_platform.py.orig	2022-08-10 01:18:14 UTC
+++ ubelt/util_platform.py
@@ -42,7 +42,7 @@ from os.path import exists, join, isdir, expanduser, n
 
 
 __all__ = [
-    'WIN32', 'LINUX', 'DARWIN', 'POSIX',
+    'WIN32', 'FREEBSD', 'LINUX', 'DARWIN', 'POSIX',
     'find_exe', 'find_path',
     'ensure_app_cache_dir', 'ensure_app_config_dir', 'ensure_app_data_dir',
     'get_app_cache_dir', 'get_app_config_dir', 'get_app_data_dir',
@@ -52,6 +52,7 @@ __all__ = [
 # References:
 # https://stackoverflow.com/questions/446209/possible-values-from-sys-platform
 WIN32  = sys.platform == 'win32'  # type: bool
+FREEBSD  = sys.platform.startswith('freebsd')  # type: bool
 LINUX  = sys.platform.startswith('linux')  # type: bool
 DARWIN = sys.platform == 'darwin'  # type: bool
 POSIX = 'posix' in sys.builtin_module_names  # type: bool
@@ -66,6 +67,8 @@ def platform_data_dir():
     """
     if LINUX:  # nocover
         dpath_ = os.environ.get('XDG_DATA_HOME', '~/.local/share')
+    elif FREEBSD:  # nocover
+        dpath_ = os.environ.get('XDG_DATA_HOME', '~/.local/share')
     elif DARWIN:  # nocover
         dpath_  = '~/Library/Application Support'
     elif WIN32:  # nocover
@@ -86,6 +89,8 @@ def platform_config_dir():
     """
     if LINUX:  # nocover
         dpath_ = os.environ.get('XDG_CONFIG_HOME', '~/.config')
+    elif FREEBSD:  # nocover
+        dpath_ = os.environ.get('XDG_CONFIG_HOME', '~/.config')
     elif DARWIN:  # nocover
         dpath_  = '~/Library/Application Support'
     elif WIN32:  # nocover
@@ -105,6 +110,8 @@ def platform_cache_dir():
         str : path to the cache dir used by the current operating system
     """
     if LINUX:  # nocover
+        dpath_ = os.environ.get('XDG_CACHE_HOME', '~/.cache')
+    elif FREEBSD:  # nocover
         dpath_ = os.environ.get('XDG_CACHE_HOME', '~/.cache')
     elif DARWIN:  # nocover
         dpath_  = '~/Library/Caches'
