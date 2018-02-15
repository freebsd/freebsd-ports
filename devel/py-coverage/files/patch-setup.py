Allow USE_PYTHON=concurrent to handle script renaming/linking for multiple
Python versions.

--- setup.py.orig	2018-01-29 11:46:04 UTC
+++ setup.py
@@ -86,12 +86,9 @@ setup_args = dict(
     },
 
     entry_points={
-        # Install a script as "coverage", and as "coverage[23]", and as
-        # "coverage-2.7" (or whatever).
+        # Install a script as "coverage"
         'console_scripts': [
             'coverage = coverage.cmdline:main',
-            'coverage%d = coverage.cmdline:main' % sys.version_info[:1],
-            'coverage-%d.%d = coverage.cmdline:main' % sys.version_info[:2],
         ],
     },
 
