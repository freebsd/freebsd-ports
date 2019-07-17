Allow USE_PYTHON=concurrent to handle script renaming/linking for multiple
Python versions.

--- setup.py.orig	2019-04-02 15:52:32 UTC
+++ setup.py
@@ -41,7 +41,6 @@ setup(
     entry_points={
         "console_scripts": [
             "nose2 = nose2:discover",
-            "nose2-%s.%s = nose2:discover" % (py_version.major, py_version.minor),
         ]
     },
     test_suite="unittest.collector",
