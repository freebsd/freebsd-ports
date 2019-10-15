Adds variable to help substitute the correct python version suffix.

--- src/main.js.orig	2019-10-07 20:11:48 UTC
+++ src/main.js
@@ -1796,7 +1796,7 @@ class BookViewerWindow {
     }
     open(fileName, realFileName, inputType = 'epub') {
         if (kindleExts.some(x => fileName.endsWith(x))) {
-            const python = GLib.find_program_in_path('python') || GLib.find_program_in_path('python3')
+            const python = GLib.find_program_in_path('@PYTHON_VERSION@')
             const kindleUnpack = pkg.pkgdatadir + '/assets/KindleUnpack/kindleunpack.py'
 
             const dir = GLib.dir_make_tmp(null)
