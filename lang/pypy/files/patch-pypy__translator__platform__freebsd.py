--- ./pypy/translator/platform/freebsd.py.orig	2012-11-22 14:52:20.000000000 +0200
+++ ./pypy/translator/platform/freebsd.py	2013-02-28 19:28:49.000000000 +0200
@@ -4,23 +4,15 @@
 
 from pypy.translator.platform import posix
 
-def get_env(key, default):
-    if key in os.environ:
-        return os.environ[key]
-    else:
-        return default
-
-def get_env_vector(key, default):
-    string = get_env(key, default)
-    # XXX: handle quotes
-    return string.split()
+if 'PYPY_LOCALBASE' not in os.environ:
+    os.environ['PYPY_LOCALBASE'] = os.environ.get('LOCALBASE', '/usr/local')
 
 class Freebsd(posix.BasePosix):
     name = "freebsd"
 
-    link_flags = ['-pthread'] + get_env_vector('LDFLAGS', '')
+    link_flags = ['-pthread'] + os.environ.get('LDFLAGS', '').split()
     cflags = ['-O3', '-pthread', '-fomit-frame-pointer'
-             ] + get_env_vector('CFLAGS', '')
+             ] + os.environ.get('CFLAGS', '').split()
     standalone_only = []
     shared_only = []
     so_ext = 'so'
@@ -28,27 +20,17 @@
 
     def __init__(self, cc=None):
         if cc is None:
-            cc = get_env("CC", "gcc")
+            cc = os.environ.get('CC', 'cc')
         super(Freebsd, self).__init__(cc)
 
     def _args_for_shared(self, args):
         return ['-shared'] + args
 
-    def _preprocess_include_dirs(self, include_dirs):
-        res_incl_dirs = list(include_dirs)
-        res_incl_dirs.append(os.path.join(get_env("LOCALBASE", "/usr/local"), "include"))
-        return res_incl_dirs
-
-    def _preprocess_library_dirs(self, library_dirs):
-        res_lib_dirs = list(library_dirs)
-        res_lib_dirs.append(os.path.join(get_env("LOCALBASE", "/usr/local"), "lib"))
-        return res_lib_dirs
-
     def _include_dirs_for_libffi(self):
-        return [os.path.join(get_env("LOCALBASE", "/usr/local"), "include")]
+        return []
 
     def _library_dirs_for_libffi(self):
-        return [os.path.join(get_env("LOCALBASE", "/usr/local"), "lib")]
+        return []
 
 class Freebsd_64(Freebsd):
     shared_only = ('-fPIC',)
