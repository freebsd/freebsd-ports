--- setup.py.orig	2020-10-29 12:35:41 UTC
+++ setup.py
@@ -137,7 +137,7 @@ def setup_package():
             url=about["__uri__"],
             license=about["__license__"],
             ext_modules=ext_modules,
-            setup_requires=["wheel>=0.32.0,<0.33.0"],
+            setup_requires=[],
             classifiers=[
                 "Development Status :: 5 - Production/Stable",
                 "Environment :: Console",
