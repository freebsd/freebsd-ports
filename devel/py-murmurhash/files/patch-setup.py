--- setup.py.orig	2020-11-02 09:42:20 UTC
+++ setup.py
@@ -137,7 +137,7 @@ def setup_package():
             url=about["__uri__"],
             license=about["__license__"],
             ext_modules=ext_modules,
-            setup_requires=["wheel"],
+            setup_requires=[],
             classifiers=[
                 "Development Status :: 5 - Production/Stable",
                 "Environment :: Console",
