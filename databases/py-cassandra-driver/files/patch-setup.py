--- setup.py.orig	2018-10-31 06:47:06 UTC
+++ setup.py
@@ -395,7 +395,7 @@ def run_setup(extensions):
         # 1.) build_ext eats errors at compile time, letting the install complete while producing useful feedback
         # 2.) there could be a case where the python environment has cython installed but the system doesn't have build tools
         if pre_build_check():
-            cython_dep = 'Cython>=0.20,!=0.25,<0.29'
+            cython_dep = 'Cython>=0.20,!=0.25,<0.30'
             user_specified_cython_version = os.environ.get('CASS_DRIVER_ALLOWED_CYTHON_VERSION')
             if user_specified_cython_version is not None:
                 cython_dep = 'Cython==%s' % (user_specified_cython_version,)
