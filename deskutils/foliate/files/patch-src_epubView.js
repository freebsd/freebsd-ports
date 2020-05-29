Adds variable to help substitute the correct python version suffix.

--- src/epubView.js.orig	2020-05-29 07:10:48 UTC
+++ src/epubView.js
@@ -36,7 +36,7 @@ var enableAnnotations = [
     mimetypes.kindleAlias,
 ]
 
-const python = GLib.find_program_in_path('python') || GLib.find_program_in_path('python3')
+const python = GLib.find_program_in_path('@PYTHON_VERSION@')
 const kindleUnpack = pkg.pkgdatadir + '/assets/KindleUnpack/kindleunpack.py'
 
 const settings = new Gio.Settings({ schema_id: pkg.name + '.view' })
