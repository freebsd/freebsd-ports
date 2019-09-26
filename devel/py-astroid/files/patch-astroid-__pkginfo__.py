--- astroid/__pkginfo__.py.orig	2019-09-24 07:23:50 UTC
+++ astroid/__pkginfo__.py
@@ -26,8 +25,7 @@ install_requires = [
     "lazy_object_proxy",
     "six",
     "wrapt",
     'typing;python_version<"3.5"',
-    'typed-ast<1.3.0;implementation_name== "cpython" and python_version<"3.7"',
-    'typed-ast>=1.3.0;implementation_name== "cpython" and python_version>="3.7" and python_version<"3.8"',
+    'typed-ast>=1.4.0,<1.5;implementation_name== "cpython" and python_version<"3.8"',
 ]
 
 # pylint: disable=redefined-builtin; why license is a builtin anyway?
