--- setup.py.orig	2019-04-25 09:34:13 UTC
+++ setup.py
@@ -27,6 +27,7 @@ setup(
     packages=['freezegun'],
     install_requires=requires,
     tests_require=tests_require,
+    test_suite='nose.collector',
     include_package_data=True,
     license='Apache 2.0',
     python_requires='>=2.7, !=3.0.*, !=3.1.*, !=3.2.*, !=3.3.*',
