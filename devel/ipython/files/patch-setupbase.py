
$FreeBSD$

--- setupbase.py.orig
+++ setupbase.py
@@ -202,7 +202,8 @@
     """
     
     docdirbase  = pjoin('share', 'doc', 'ipython')
-    manpagebase = pjoin('share', 'man', 'man1')
+    manpagebase = pjoin('man', 'man1')
+    examplebase = pjoin('share', 'examples', 'ipython')
     
     # Simple file lists can be made by hand
     manpages  = filter(isfile, glob(pjoin('docs','man','*.1.gz')))
@@ -216,7 +217,7 @@
     example_files = make_dir_struct(
         'data',
         pjoin('docs','examples'),
-        pjoin(docdirbase,'examples')
+        pjoin(examplebase)
     )
     manual_files = make_dir_struct(
         'data',
