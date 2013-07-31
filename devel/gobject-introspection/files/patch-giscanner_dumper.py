--- giscanner/dumper.py.orig	2013-02-23 11:40:08.000000000 +0100
+++ giscanner/dumper.py	2013-06-28 21:51:35.000000000 +0200
@@ -89,8 +89,9 @@
         # Enable the --msvc-syntax pkg-config flag when
         # the Microsoft compiler is used
         # (This is the other way to check whether Visual C++ is used subsequently)
-        if 'cl' in self._compiler_cmd:
-            self._pkgconfig_msvc_flags = '--msvc-syntax'
+        if 'clang' not in self._compiler_cmd:
+            if 'cl' in self._compiler_cmd:
+                self._pkgconfig_msvc_flags = '--msvc-syntax'
         self._uninst_srcdir = os.environ.get(
             'UNINSTALLED_INTROSPECTION_SRCDIR')
         self._packages = ['gio-2.0 gmodule-2.0']
