--- setup.py.orig	2015-03-27 14:08:24 UTC
+++ setup.py
@@ -4,7 +4,7 @@
 import os
 import uuid
 
-from pip.req import parse_requirements
+from pkg_resources import parse_requirements
 from setuptools import find_packages
 from setuptools import setup
 from setuptools.command.build_py import build_py
@@ -63,10 +63,10 @@ class my_build_py(build_py):
         # distutils uses old-style classes, so no super()
         build_py.run(self)
 
-test_reqs_gen = parse_requirements("test-requirements.txt",
-                                  session=uuid.uuid1())
-reqs_gen = parse_requirements("requirements.txt",
-                              session=uuid.uuid1())
+with open("test-requirements.txt") as f:
+    test_reqs = [str(req) for req in parse_requirements(f.read())]
+with open("requirements.txt") as f:
+    reqs = [str(req) for req in parse_requirements(f.read())]
 
 
 setup(name='period',
@@ -93,5 +93,5 @@ setup(name='period',
       include_package_data=True,
       zip_safe=False,
       test_suite='nose.collector',
-      tests_require=[str(ir.req) for ir in test_reqs_gen],
-      install_requires=[str(ir.req) for ir in reqs_gen], )
+      tests_require=test_reqs,
+      install_requires=reqs)
