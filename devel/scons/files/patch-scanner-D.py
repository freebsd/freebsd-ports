--- engine/SCons/Scanner/D.py.orig	Wed Feb 16 03:12:10 2005
+++ engine/SCons/Scanner/D.py	Tue Mar  1 22:00:50 2005
@@ -51,7 +51,5 @@
         # translate dots (package separators) to slashes
         inc = string.replace(include, '.', '/')
 
-        i = SCons.Node.FS.find_file(inc + '.d',
-                                    (source_dir,) + path,
-                                    self.fs.File)
+        i = SCons.Node.FS.find_file(inc + '.d', (source_dir,) + path)
         return i, include
