--- src/epubView.js.orig	2020-04-06 13:22:39 UTC
+++ src/epubView.js
@@ -21,7 +21,7 @@ const {
     mimetypes, execCommand, recursivelyDeleteDir
 } = imports.utils
 
-const python = GLib.find_program_in_path('python') || GLib.find_program_in_path('python3')
+const python = GLib.find_program_in_path('@PYTHON_VERSION@')
 const kindleUnpack = pkg.pkgdatadir + '/assets/KindleUnpack/kindleunpack.py'
 
 const settings = new Gio.Settings({ schema_id: pkg.name + '.view' })
