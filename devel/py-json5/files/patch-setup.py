--- setup.py.orig	2019-06-12 17:08:19 UTC
+++ setup.py
@@ -30,7 +30,6 @@ with open(os.path.join(here, 'README.md'
 setup(
     name='json5',
     packages=find_packages(),
-    package_data={'': ['../README.md']},
     entry_points={
         'console_scripts': [
             'pyjson5=json5.tool:main',
