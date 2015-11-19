# Do not bundle libcapstone.so

--- setup.py.orig	2015-07-15 07:43:18 UTC
+++ setup.py
@@ -175,17 +175,4 @@ setup(
         'Programming Language :: Python :: 3',
     ],
     requires=['ctypes'],
-    cmdclass=dict(
-        build_clib=custom_build_clib,
-        sdist=custom_sdist,
-    ),
-
-    libraries=[(
-        'capstone', dict(
-            package='capstone',
-            sources=dummy_src()
-        ),
-    )],
-
-    data_files=[(SITE_PACKAGES, SETUP_DATA_FILES)],
 )
