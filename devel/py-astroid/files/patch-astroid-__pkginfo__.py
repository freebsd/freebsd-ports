--- astroid/__pkginfo__.py.orig	2019-11-06 18:41:21 UTC
+++ astroid/__pkginfo__.py
@@ -24,7 +24,7 @@ extras_require = {}
 install_requires = [
     "lazy_object_proxy==1.4.*",
     "six~=1.12",
-    "wrapt==1.11.*",
+    "wrapt>=1.11.0,<1.13",
     'typed-ast>=1.4.0,<1.5;implementation_name== "cpython" and python_version<"3.8"',
 ]
 
