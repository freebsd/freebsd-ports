--- setup.py.orig	2024-07-31 02:05:53 UTC
+++ setup.py
@@ -89,12 +89,9 @@ setup_args = dict(
         ],
     },
     entry_points={
-        # Install a script as "coverage", and as "coverage3", and as
-        # "coverage-3.7" (or whatever).
+        # Install a script as "coverage".
         "console_scripts": [
             "coverage = coverage.cmdline:main",
-            "coverage%d = coverage.cmdline:main" % sys.version_info[:1],
-            "coverage-%d.%d = coverage.cmdline:main" % sys.version_info[:2],
         ],
     },
     extras_require={
