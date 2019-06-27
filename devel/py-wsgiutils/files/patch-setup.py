--- setup.py.orig	2019-06-26 18:43:04 UTC
+++ setup.py
@@ -34,6 +34,7 @@ setup(name="WSGIUtils",
 		'wsgiutils',
 	],
 	package_dir = {'': 'lib'},
+       use_2to3=True,
 	classifiers = [
 		'Development Status :: 5 - Production/Stable',
 		'Intended Audience :: Developers',
