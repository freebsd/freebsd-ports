--- setup.py.orig	2021-04-14 13:08:50.055448000 +0200
+++ setup.py	2021-04-14 13:12:54.776586000 +0200
@@ -67,7 +67,6 @@
         zip_safe=False,
         setup_requires=[
             "docutils",
-            "twine",
             ],
         test_suite="setup.test_suite",
         tests_require=test_requirements,
@@ -98,11 +97,6 @@
             "Topic :: Software Development :: Libraries :: Python Modules",
             ],
         )
-
-# Docutils is only required for building, but Setuptools can't distinguish
-# dependencies properly.
-# See <URL:https://github.com/pypa/setuptools/issues/457>.
-setup_kwargs['install_requires'].append("docutils")
 
 
 if __name__ == '__main__':
