--- setup.py.orig	2025-11-13 20:57:16 UTC
+++ setup.py
@@ -421,7 +421,7 @@ class hgbuildext(build_ext):
                 )
 
             for rustext in ruststandalones:
-                rustext.build('' if self.editable_mode else self.build_lib)
+                rustext.build(self.build_lib)
 
         return build_ext.build_extensions(self)
 
@@ -515,12 +515,8 @@ class hgbuildpy(build_py):
             ]
         )
 
-        if self.editable_mode:
-            here = os.path.dirname(__file__)
-            basepath = os.path.join(here, 'mercurial')
-        else:
-            basepath = os.path.join(self.build_lib, 'mercurial')
-            self.mkpath(basepath)
+        basepath = os.path.join(self.build_lib, 'mercurial')
+        self.mkpath(basepath)
 
         write_if_changed(os.path.join(basepath, '__modulepolicy__.py'), content)
 
