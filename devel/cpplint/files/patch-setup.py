--- setup.py.orig	2021-05-20 10:29:07 UTC
+++ setup.py
@@ -72,9 +72,6 @@ setup(name='cpplint',
       description='Automated checker to ensure C++ files follow Google\'s style guide',
       long_description=open('README.rst').read(),
       license='BSD-3-Clause',
-      setup_requires=[
-          "pytest-runner==5.2"
-      ],
       tests_require=test_required,
       # extras_require allow pip install .[dev]
       extras_require={
