--- ./setup.py.orig	2013-12-01 01:57:47.387343670 +1100
+++ ./setup.py	2013-12-01 01:58:01.182641877 +1100
@@ -73,9 +73,6 @@
             "github",
             "github.tests",
         ],
-        package_data={
-            "github": ["ReadMe.rst", "COPYING*", "tests/ReplayData/*.txt"]
-        },
         classifiers=[
             "Development Status :: 5 - Production/Stable",
             "Environment :: Web Environment",
