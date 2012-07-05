--- ./setup.py.orig	2012-06-29 17:52:26.000000000 +1000
+++ ./setup.py	2012-06-29 17:52:35.000000000 +1000
@@ -54,9 +54,6 @@
     packages = [
         "github",
     ],
-    package_data = {
-        "github": [ "../ReadMe.md", "../COPYING*", "../doc/*.md" ]
-    },
     classifiers = [
         "Development Status :: 5 - Production/Stable",
         "Environment :: Web Environment",
