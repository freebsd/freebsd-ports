# Upstream creates a nose2-X.Y script name already
# Port uses concurrent, which creates nose2-X.Y-X.Y
# duplicate suffix

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
