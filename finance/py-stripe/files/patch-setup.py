# pytest-cov is not a compulsory test dependency
# TODO: Upstream

--- setup.py.orig	2019-04-08 18:44:53 UTC
+++ setup.py
@@ -54,8 +54,10 @@ setup(
         "pytest >= 3.4",
         "pytest-mock >= 1.7",
         "pytest-xdist >= 1.22",
-        "pytest-cov >= 2.5",
     ],
+    extras_require={
+        'dev': ['pytest-cov >= 2.5'],
+    },
     cmdclass={"test": PyTest},
     project_urls={
         "Bug Tracker": "https://github.com/stripe/stripe-python/issues",
