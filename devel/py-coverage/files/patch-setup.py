Allow USE_PYTHON=concurrent to handle script renaming/linking for multiple
Python versions.

--- setup.py.orig	2022-02-20 22:41:35 UTC
+++ setup.py
@@ -97,12 +97,9 @@ setup_args = dict(
     },
 
     entry_points={
-        # Install a script as "coverage", and as "coverage3", and as
-        # "coverage-3.7" (or whatever).
+        # Install a script as "coverage".
         'console_scripts': [
             'coverage = coverage.cmdline:main',
-            'coverage%d = coverage.cmdline:main' % sys.version_info[:1],
-            'coverage-%d.%d = coverage.cmdline:main' % sys.version_info[:2],
         ],
     },
 
