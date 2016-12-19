# Do not bundle libunicorn.so

--- setup.py.orig	2015-10-15 16:22:04 UTC
+++ setup.py
@@ -166,17 +166,4 @@ setup(
         'Programming Language :: Python :: 3',
     ],
     requires=['ctypes'],
-    cmdclass=dict(
-        build_clib=custom_build_clib,
-        sdist=custom_sdist,
-    ),
-
-    libraries=[(
-        'unicorn', dict(
-            package='unicorn',
-            sources=dummy_src()
-        ),
-    )],
-
-    data_files=[(SITE_PACKAGES, SETUP_DATA_FILES)],
 )
