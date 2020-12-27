# Do not bundle libunicorn.so

--- setup.py.orig	2020-09-21 18:11:43 UTC
+++ setup.py
@@ -281,11 +281,4 @@ setup(
         'Programming Language :: Python :: 3',
     ],
     requires=['ctypes'],
-    cmdclass={'build': custom_build, 'develop': custom_develop, 'sdist': custom_sdist, 'bdist_egg': custom_bdist_egg},
-    zip_safe=False,
-    include_package_data=True,
-    is_pure=False,
-    package_data={
-        'unicorn': ['lib/*', 'include/unicorn/*']
-    }
 )
