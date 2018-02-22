Allow USE_PYTHON=concurrent to handle script renaming/linking for multiple
Python versions.

--- setup.py.orig	2018-01-29 12:01:44 UTC
+++ setup.py
@@ -89,7 +89,6 @@ else:
     params['entry_points'] = {
         'console_scripts': [
             '%s = nose2:discover' % SCRIPT1,
-            '%s = nose2:discover' % SCRIPT2,
         ],
     }
     params['install_requires'] = parse_requirements('requirements.txt')
