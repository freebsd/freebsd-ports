--- src/dispatch/__init__.py.orig	2009-05-14 22:55:09.000000000 +0200
+++ src/dispatch/__init__.py	2009-05-14 22:55:45.000000000 +0200
@@ -95,7 +95,7 @@
     return decorate_assignment(callback)
 
 
-def as(*decorators):
+def fas(*decorators):
     """Use Python 2.4 decorators w/Python 2.2+
 
     Example:
@@ -103,7 +103,7 @@
         import dispatch
 
         class Foo(object):
-            [dispatch.as(classmethod)]
+            [dispatch.fas(classmethod)]
             def something(cls,etc):
                 \"""This is a classmethod\"""
     """
