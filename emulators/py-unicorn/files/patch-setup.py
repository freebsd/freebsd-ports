# Do not bundle libunicorn.so

--- setup.py.orig	2020-05-29 03:56:24 UTC
+++ setup.py
@@ -289,11 +289,4 @@ setup(
         'Programming Language :: Python :: 3',
     ],
     requires=['ctypes'],
-    cmdclass=cmdclass,
-    zip_safe=True,
-    include_package_data=True,
-    is_pure=True,
-    package_data={
-        'unicorn': ['lib/*', 'include/unicorn/*']
-    }
 )
