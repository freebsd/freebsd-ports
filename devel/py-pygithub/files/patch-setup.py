--- ./setup.py.orig	2012-10-06 17:07:20.000000000 +1000
+++ ./setup.py	2012-10-06 17:07:31.000000000 +1000
@@ -68,9 +68,6 @@
         "github",
         "github.tests",
     ],
-    package_data = {
-        "github": [ "ReadMe.md", "COPYING*", "doc/*.md", "tests/ReplayData/*.txt" ]
-    },
     classifiers = [
         "Development Status :: 5 - Production/Stable",
         "Environment :: Web Environment",
