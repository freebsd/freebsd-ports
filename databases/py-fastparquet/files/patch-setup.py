--- setup.py.orig	2022-11-18 01:33:09 UTC
+++ setup.py
@@ -44,7 +44,6 @@ else:
     extra = {'ext_modules': cythonize(modules, language_level=3)}
 
 install_requires = open('requirements.txt').read().strip().split('\n')
-subprocess.call(["git", "status"], stdout=sys.stdout, stderr=sys.stderr)
 
 setup(
     name='fastparquet',
@@ -57,8 +56,7 @@ setup(
         'setuptools>18.0',
         'setuptools-scm>1.5.4',
         'Cython',
-        'pytest-runner',
-        'oldest-supported-numpy'
+        'numpy'
     ],
     description='Python support for Parquet file format',
     author='Martin Durant',
