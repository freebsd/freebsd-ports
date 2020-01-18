# Do not bundle libunicorn.so

--- setup.py.orig	2019-10-08 02:44:50 UTC
+++ setup.py
@@ -268,11 +268,4 @@ setup(
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
