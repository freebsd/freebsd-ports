--- tools/gn/build/gen.py.orig	2025-08-26 20:49:50 UTC
+++ tools/gn/build/gen.py
@@ -94,6 +94,12 @@ class Platform(object):
   def is_solaris(self):
     return self._platform == 'solaris'
 
+  def is_openbsd(self):
+    return self._platform == 'openbsd'
+
+  def is_freebsd(self):
+    return self._platform == 'freebsd'
+
   def is_posix(self):
     return self._platform in ['linux', 'freebsd', 'darwin', 'aix', 'openbsd', 'haiku', 'solaris', 'msys', 'netbsd', 'serenity']
 
@@ -308,7 +314,7 @@ def WriteGenericNinja(path, static_libraries, executab
       'linux': 'build_linux.ninja.template',
       'freebsd': 'build_linux.ninja.template',
       'aix': 'build_aix.ninja.template',
-      'openbsd': 'build_openbsd.ninja.template',
+      'openbsd': 'build_linux.ninja.template',
       'haiku': 'build_haiku.ninja.template',
       'solaris': 'build_linux.ninja.template',
       'netbsd': 'build_linux.ninja.template',
@@ -552,6 +558,9 @@ def WriteGNNinja(path, platform, host, options, args_l
 
     if platform.is_posix() and not platform.is_haiku():
       ldflags.append('-pthread')
+
+    if platform.is_openbsd():
+      libs.append('-lkvm')
 
     if platform.is_mingw() or platform.is_msys():
       cflags.extend(['-DUNICODE',
