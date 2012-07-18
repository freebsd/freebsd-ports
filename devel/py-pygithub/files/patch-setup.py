--- ./setup.py.orig	2012-07-13 21:42:12.000000000 +1000
+++ ./setup.py	2012-07-14 19:15:08.000000000 +1000
@@ -54,9 +54,6 @@
     packages = [
         "github",
     ],
-    package_data = {
-        "github": [ "ReadMe.md", "COPYING*", "doc/*.md" ]
-    },
     classifiers = [
         "Development Status :: 5 - Production/Stable",
         "Environment :: Web Environment",
