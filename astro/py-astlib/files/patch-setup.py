--- setup.py.orig	2026-02-12 09:30:47 UTC
+++ setup.py
@@ -56,7 +56,7 @@ class build_PyWCSTools_ext(build_ext):
 
         build_ext.build_extensions(self)
 
-setup(name='astLib',
+setup(name='astlib',
     version='0.13.2',
     packages=['astLib', 'PyWCSTools'],
     package_data={'astLib': ['data/*']},
