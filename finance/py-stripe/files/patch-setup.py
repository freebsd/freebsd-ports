# Use latest mock for tests
# Fix two test failures with latest mock #205 
# https://github.com/stripe/stripe-python/issues/205

--- setup.py.orig	2016-02-22 10:32:35 UTC
+++ setup.py
@@ -57,7 +57,7 @@ setup(
     package_data={'stripe': ['data/ca-certificates.crt']},
     install_requires=install_requires,
     test_suite='stripe.test.all',
-    tests_require=['unittest2', 'mock == 1.0.1'],
+    tests_require=['unittest2', 'mock>=1.0.1'],
     use_2to3=True,
     classifiers=[
         "Development Status :: 5 - Production/Stable",
