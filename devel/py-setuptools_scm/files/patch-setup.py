--- setup.py.orig	2018-08-09 06:35:22 UTC
+++ setup.py
@@ -22,7 +22,7 @@ def scm_config():
     has_entrypoints = os.path.isdir(egg_info)
     import pkg_resources
 
-    sys.path.insert(0, src)
+    sys.path.insert(0, here)
     pkg_resources.working_set.add_entry(src)
     from setuptools_scm.hacks import parse_pkginfo
     from setuptools_scm.git import parse as parse_git
