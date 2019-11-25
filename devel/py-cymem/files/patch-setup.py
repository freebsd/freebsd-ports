--- setup.py.orig	2019-11-13 12:12:11 UTC
+++ setup.py
@@ -121,7 +121,7 @@ def setup_package():
             url=about["__uri__"],
             license=about["__license__"],
             ext_modules=ext_modules,
-            setup_requires=["wheel>=0.32.0,<0.33.0"],
+            setup_requires=[],
             classifiers=[
                 "Environment :: Console",
                 "Intended Audience :: Developers",
