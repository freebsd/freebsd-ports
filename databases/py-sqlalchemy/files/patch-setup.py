$FreeBSD$
--- setup.py.orig	2012-03-15 05:23:20.000000000 +0100
+++ setup.py	2012-04-10 19:19:38.000000000 +0200
@@ -128,7 +128,7 @@
           package_dir={'': 'lib'},
           license="MIT License",
           cmdclass=cmdclass,
-
+          zip_safe=False,
           tests_require=['nose >= 0.11'],
           test_suite="sqla_nose",
           long_description=readme,
