--- setup.py.orig	2021-02-18 20:19:33 UTC
+++ setup.py
@@ -45,7 +45,6 @@ class TestCommand(test):
 
 setup(
     name='dotty_dict',
-    version=get_version('dotty_dict', '__init__.py'),
     description="Dictionary wrapper for quick access to deeply nested keys.",
     long_description=readme,
     license="MIT license",
@@ -55,8 +54,6 @@ setup(
     packages=find_packages(exclude=('tests', 'docs', 'bin', 'example')),
     package_dir={'dotty_dict': 'dotty_dict'},
     include_package_data=True,
-    use_scm_version=True,
-    install_requires=['setuptools_scm'],
     zip_safe=False,
     keywords='dot notation dict wrapper helper utils lib',
     classifiers=[
