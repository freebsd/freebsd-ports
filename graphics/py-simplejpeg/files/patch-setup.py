-- Add FreeBSD to the platforms recognized by the build script so that the
-- bundled libjpeg-turbo is built with CMake and the correct static library
-- name is selected.
--- setup.py.orig	2025-10-10 10:46:58 UTC
+++ setup.py
@@ -112,7 +112,7 @@ def make_type():
 
 
 def make_type():
-    if OS in ('linux', 'darwin'):
+    if OS in ('linux', 'darwin', 'freebsd'):
         return 'Unix Makefiles'
     elif OS == 'windows':
         return 'NMake Makefiles'
@@ -196,7 +196,7 @@ def _staticlib():
 
 
 def _staticlib():
-    if OS in ('linux', 'darwin'):
+    if OS in ('linux', 'darwin', 'freebsd'):
         return 'libturbojpeg.a'
     elif OS == 'windows':
         return 'turbojpeg-static.lib'
