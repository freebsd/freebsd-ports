--- setupbase.py.orig	2016-08-13 12:56:43 UTC
+++ setupbase.py
@@ -203,7 +203,7 @@ def find_data_files():
     Just man pages at this point.
     """
 
-    manpagebase = pjoin('share', 'man', 'man1')
+    manpagebase = pjoin('man', 'man1')
 
     # Simple file lists can be made by hand
     manpages = [f for f in glob(pjoin('docs','man','*.1.gz')) if isfile(f)]
