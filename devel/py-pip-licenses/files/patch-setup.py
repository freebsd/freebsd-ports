--- setup.py.orig	2020-02-16 05:37:47 UTC
+++ setup.py
@@ -91,9 +91,6 @@ setup(
     license=LICENSE,
     python_requires='~=3.5',
     install_requires=['PTable'],
-    setup_requires=[
-        'pytest-runner',
-    ],
     tests_require=TEST_DEPENDS,
     extras_require={
         'test': TEST_DEPENDS,
