--- setup.py.orig	2016-03-03 08:44:23 UTC
+++ setup.py
@@ -11,6 +11,11 @@ else:
     # Py3k
     requires += ['python-dateutil>=2.0']
 
+tests_require = [
+    'nose',
+    'mock',
+]
+
 setup(
     name='freezegun',
     version='0.3.6',
@@ -20,6 +25,8 @@ setup(
     url='https://github.com/spulec/freezegun',
     packages=['freezegun'],
     install_requires=requires,
+    tests_require=tests_require,
+    test_suite='nose.collector',
     include_package_data=True,
     license='Apache 2.0',
     classifiers=[
