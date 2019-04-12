--- setup.py.orig	2018-08-14 08:49:36 UTC
+++ setup.py
@@ -33,8 +33,8 @@ setup(name="WSGIUtils",
 	packages=[
 		'wsgiutils',
 	],
-	data_files = [('', ['LICENSE.txt', 'README.txt'])],
 	package_dir = {'': 'lib'},
+        use_2to3=True,
 	classifiers = [
 		'Development Status :: 5 - Production/Stable',
 		'Intended Audience :: Developers',
