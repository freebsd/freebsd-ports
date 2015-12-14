--- setup.py.orig	2015-12-14 11:12:47 UTC
+++ setup.py
@@ -54,5 +54,6 @@ setuptools.setup(
     install_requires=install_requires,
     extras_require={
         'test': tests_require
-    }
+    },
+    test_suite='icalendar.tests',
 )
