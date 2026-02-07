--- aksetup_helper.py.orig	2014-05-26 05:39:30 UTC
+++ aksetup_helper.py
@@ -131,7 +131,7 @@ def get_config(schema=None, warn_about_n
     return expand_options(schema.read_config())
 
 
-def hack_distutils(debug=False, fast_link=True, what_opt=3):
+def hack_distutils(debug=False, fast_link=True, what_opt=None):
     # hack distutils.sysconfig to eliminate debug flags
     # stolen from mpi4py
 
