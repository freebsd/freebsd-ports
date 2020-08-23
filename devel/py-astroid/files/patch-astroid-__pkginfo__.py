--- astroid/__pkginfo__.py.orig	2020-06-08 06:51:41 UTC
+++ astroid/__pkginfo__.py
@@ -26,7 +26,7 @@ numversion = tuple(int(elem) for elem in version.split
 
 extras_require = {}
 install_requires = [
-    "lazy_object_proxy==1.4.*",
+    "lazy_object_proxy>=1.4",
     "six~=1.12",
     "wrapt~=1.11",
     'typed-ast>=1.4.0,<1.5;implementation_name== "cpython" and python_version<"3.8"',
