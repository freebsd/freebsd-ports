--- ubelt/util_platform.py.orig	2026-02-08 23:19:13 UTC
+++ ubelt/util_platform.py
@@ -53,6 +53,7 @@ __all__ = [
 __all__ = [
     'WIN32',
     'LINUX',
+    'FREEBSD',
     'DARWIN',
     'POSIX',
     'find_exe',
@@ -86,6 +87,8 @@ def platform_data_dir() -> str:
     """
     if POSIX:  # nocover
         dpath_ = os.environ.get('XDG_DATA_HOME', '~/.local/share')
+    elif FREEBSD:  # nocover
+        dpath_ = os.environ.get('XDG_DATA_HOME', '~/.local/share')
     elif DARWIN:  # nocover
         dpath_ = '~/Library/Application Support'
     elif WIN32:  # nocover
@@ -105,6 +108,8 @@ def platform_config_dir() -> str:
         str : path to the cache dir used by the current operating system
     """
     if POSIX:  # nocover
+        dpath_ = os.environ.get('XDG_CONFIG_HOME', '~/.config')
+    elif FREEBSD:  # nocover
         dpath_ = os.environ.get('XDG_CONFIG_HOME', '~/.config')
     elif DARWIN:  # nocover
         dpath_ = '~/Library/Application Support'
