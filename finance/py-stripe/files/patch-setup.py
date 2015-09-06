--- setup.py.orig	2015-09-06 11:22:57 UTC
+++ setup.py
@@ -54,7 +54,7 @@ setup(
     author_email='support@stripe.com',
     url='https://github.com/stripe/stripe-python',
     packages=['stripe', 'stripe.test'],
-    package_data={'stripe': ['data/ca-certificates.crt', '../VERSION']},
+    package_data={'stripe': ['data/ca-certificates.crt']},
     install_requires=install_requires,
     test_suite='stripe.test.all',
     use_2to3=True,
