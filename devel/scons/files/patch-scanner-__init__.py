--- engine/SCons/Scanner/__init__.py.orig	Wed Feb 16 03:12:10 2005
+++ engine/SCons/Scanner/__init__.py	Tue Mar  1 22:00:50 2005
@@ -338,9 +338,7 @@
     def find_include(self, include, source_dir, path):
         "__cacheable__"
         if callable(path): path = path()
-        n = SCons.Node.FS.find_file(include,
-                                    (source_dir,) + tuple(path),
-                                    SCons.Node.FS.File)
+        n = SCons.Node.FS.find_file(include, (source_dir,) + tuple(path))
         return n, include
 
     def sort_key(self, include):
@@ -398,9 +396,7 @@
         else:
             paths = Binder( tuple(path) + (source_dir,) )
 
-        n = SCons.Node.FS.find_file(include[1],
-                                    paths,
-                                    self.fs.File)
+        n = SCons.Node.FS.find_file(include[1], paths)
 
         return n, include[1]
 
