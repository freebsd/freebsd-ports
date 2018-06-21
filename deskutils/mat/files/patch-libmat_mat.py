--- libmat/mat.py.orig	2018-03-18 17:33:51 UTC
+++ libmat/mat.py
@@ -116,10 +116,8 @@ def secure_remove(filename):
         raise libmat.exceptions.UnableToWriteFile
 
     try:
-        shred = 'shred'
-        if platform.system() == 'MacOS':
-            shred = 'gshred'
-        if not subprocess.call([shred, '--remove', filename]):
+        shred = 'srm'
+        if not subprocess.call([shred, filename]):
             return True
         else:
             raise OSError
