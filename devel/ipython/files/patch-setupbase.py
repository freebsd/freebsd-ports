--- setupbase.py.orig	2024-01-27 00:28:40 UTC
+++ setupbase.py
@@ -145,10 +145,7 @@ def find_data_files():
     Just man pages at this point.
     """
 
-    if "freebsd" in sys.platform:
-        manpagebase = pjoin('man', 'man1')
-    else:
-        manpagebase = pjoin('share', 'man', 'man1')
+    manpagebase = pjoin('share', 'man', 'man1')
 
     # Simple file lists can be made by hand
     manpages = [f for f in glob(pjoin('docs','man','*.1.gz')) if isfile(f)]
@@ -346,4 +343,3 @@ def git_prebuild(pkg_dir, build_cmd=build_py):
                 )
 
     return MyBuildPy
-
