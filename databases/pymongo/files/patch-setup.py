--- setup.py.orig	2013-05-26 10:11:36.000000000 +0000
+++ setup.py	2013-05-26 11:26:48.000000000 +0000
@@ -289,6 +289,7 @@
     features=features,
     license="Apache License, Version 2.0",
     tests_require=["nose"],
+    zip_safe=False,
     classifiers=[
         "Development Status :: 5 - Production/Stable",
         "Intended Audience :: Developers",
