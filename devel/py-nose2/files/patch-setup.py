# Upstream creates a nose2-X.Y script name already
# Port uses concurrent, which creates nose2-X.Y-X.Y
# duplicate suffix

--- setup.py.orig	2021-12-28 13:51:49 UTC
+++ setup.py
@@ -38,7 +38,6 @@ setup(
     entry_points={
         "console_scripts": [
             "nose2 = nose2:discover",
-            "nose2-%s = nose2:discover" % PY_VERSION,
         ]
     },
     test_suite="unittest.collector",
