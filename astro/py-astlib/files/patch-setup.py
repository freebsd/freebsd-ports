--- setup.py.orig	2023-10-19 08:41:05 UTC
+++ setup.py
@@ -55,7 +55,7 @@ class build_PyWCSTools_ext(build_ext):
 
         build_ext.build_extensions(self)
 
-setup(name='astLib',
+setup(name='astlib',
     version='0.11.10',
     packages=['astLib', 'PyWCSTools'],
     package_data={'astLib': ['data/*']},
