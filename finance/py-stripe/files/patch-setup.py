--- setup.py.orig	2016-03-03 09:42:16 UTC
+++ setup.py
@@ -28,6 +28,11 @@ if sys.version_info < (2, 6):
 else:
     install_requires.append('requests >= 0.8.8')
 
+tests_require = [
+    'unittest2',
+    'pycurl>=7.19',
+    'mock',
+]
 
 with open('LONG_DESCRIPTION.rst') as f:
     long_description = f.read()
@@ -56,8 +61,8 @@ setup(
     packages=['stripe', 'stripe.test', 'stripe.test.resources'],
     package_data={'stripe': ['data/ca-certificates.crt']},
     install_requires=install_requires,
+    tests_require=tests_require,
     test_suite='stripe.test.all',
-    tests_require=['unittest2', 'mock'],
     use_2to3=True,
     classifiers=[
         "Development Status :: 5 - Production/Stable",
