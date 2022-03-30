--- setup.py.orig	2014-08-11 21:55:01 UTC
+++ setup.py
@@ -21,7 +21,7 @@ setup(name=__title__,
       long_description=long_desc,
       license=__license__,
       platforms=['linux'],
-      packages=find_packages(exclude=["*.tests"]),
+      packages=find_packages(exclude=["tests"]),
       install_requires=['requests', ],
       requires=['requests', ],
       provides=[__title__, ],
