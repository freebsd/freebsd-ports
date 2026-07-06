--- breezy/git/dir.py.orig	2022-02-02 23:16:49 UTC
+++ breezy/git/dir.py
@@ -67,7 +67,7 @@ class GitControlDirFormat(ControlDirFormat):
     fixed_components = True
 
     def __eq__(self, other):
-        return type(self) == type(other)
+        return type(self) is type(other)
 
     def is_supported(self):
         return True
