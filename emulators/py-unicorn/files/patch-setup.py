# Do not bundle libunicorn.so

--- setup.py.orig	2022-11-16 14:16:49 UTC
+++ setup.py
@@ -246,11 +246,4 @@ setup(
         'Programming Language :: Python :: 3',
     ],
     requires=['ctypes'],
-    cmdclass=cmdclass,
-    zip_safe=False,
-    include_package_data=True,
-    is_pure=False,
-    package_data={
-        'unicorn': ['lib/*', 'include/unicorn/*']
-    }
 )
