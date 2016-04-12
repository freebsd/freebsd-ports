--- setup.py.orig	2016-04-01 05:26:33 UTC
+++ setup.py
@@ -28,7 +28,7 @@ setup(
     license='BSD-3-Clause',
     packages=['pytest_django'],
     long_description=read('README.rst'),
-    setup_requires=['setuptools_scm==1.8.0'],
+    setup_requires=['setuptools_scm>=1.8.0'],
     install_requires=['pytest>=2.5'],
     classifiers=['Development Status :: 5 - Production/Stable',
                  'Framework :: Django',
