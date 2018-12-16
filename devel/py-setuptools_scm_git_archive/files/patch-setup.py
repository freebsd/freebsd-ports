--- setup.py.orig	2015-11-29 14:26:35 UTC
+++ setup.py
@@ -26,9 +26,4 @@ meta = dict(
 # Clean up first, old eggs seem to confuse setuptools_scm
 rmtree(meta['name']+'.egg-info', ignore_errors=True)
 
-# Bootstrap
-if not isdir('.git'):
-    setup(version='0', **meta)
-    working_set.add_entry('.')
-
 setup(use_scm_version=True, **meta)
