--- setupbase.py.orig	2008-09-15 05:26:16.000000000 +0800
+++ setupbase.py	2008-10-03 13:45:28.000000000 +0800
@@ -188,7 +188,8 @@
     """
     
     docdirbase  = 'share/doc/ipython'
-    manpagebase = 'share/man/man1'
+    manpagebase = 'man/man1'
+    examplebase = 'share/examples/ipython'
 
     # Simple file lists can be made by hand
     manpages  = filter(isfile, glob('docs/man/*.1.gz'))
@@ -196,7 +197,7 @@
 
     # For nested structures, use the utility above
     example_files = make_dir_struct('data','docs/examples',
-                                    pjoin(docdirbase,'examples'))
+                                    examplebase)
     manual_files = make_dir_struct('data','docs/dist',pjoin(docdirbase,'manual'))
 
     # And assemble the entire output list
