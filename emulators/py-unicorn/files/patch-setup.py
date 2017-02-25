# Do not bundle libunicorn.so

--- setup.py.orig	2017-02-23 12:57:14 UTC
+++ setup.py
@@ -260,11 +260,4 @@ setup(
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
