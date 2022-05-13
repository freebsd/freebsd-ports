--- setup.py.orig	2020-09-28 20:11:31 UTC
+++ setup.py
@@ -49,7 +49,7 @@ setup(
     packages=find_packages('src'),
     package_dir={'': 'src'},
     install_requires=[
-        'arpeggio ~= 1.7',
+        'arpeggio >= 1.7',
         'attrs >= 19.2',
         'six ~= 1.13',
     ],
