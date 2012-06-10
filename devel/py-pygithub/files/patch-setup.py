--- ./setup.py.orig	2012-06-04 19:29:37.000000000 +1000
+++ ./setup.py	2012-06-04 19:29:46.000000000 +1000
@@ -54,9 +54,6 @@
     packages = [
         "github",
     ],
-    data_files = [
-        ( "", [ "ReadMe.md", "COPYING", "COPYING.LESSER", "doc/ReferenceOfClasses.md", "doc/ReferenceOfApis.md", "doc/Design.md" ] ),
-    ],
     classifiers=[
         "Development Status :: 5 - Production/Stable",
         "Environment :: Web Environment",
