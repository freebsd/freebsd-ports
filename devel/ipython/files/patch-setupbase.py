
$FreeBSD$

--- setupbase.py.orig
+++ setupbase.py
@@ -201,7 +201,8 @@
     """
 
     docdirbase  = pjoin('share', 'doc', 'ipython')
-    manpagebase = pjoin('share', 'man', 'man1')
+    manpagebase = pjoin('man', 'man1')
+    examplebase = pjoin('share', 'examples', 'ipython')
 
     # Simple file lists can be made by hand
     manpages = [f for f in glob(pjoin('docs','man','*.1.gz')) if isfile(f)]
@@ -215,7 +216,7 @@
     example_files = make_dir_struct(
         'data',
         pjoin('docs','examples'),
-        pjoin(docdirbase,'examples')
+        pjoin(examplebase)
     )
     manual_files = make_dir_struct(
         'data',
@@ -225,7 +226,6 @@
 
     # And assemble the entire output list
     data_files = [ (manpagebase, manpages),
-                   (pjoin(docdirbase, 'extensions'), igridhelpfiles),
                    ] + manual_files + example_files
 
     return data_files
