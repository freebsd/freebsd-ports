--- ast/c_visitor_impl.py.orig	2017-10-16 21:39:41 UTC
+++ ast/c_visitor_impl.py
@@ -16,8 +16,8 @@ class Printer(object):
     self._types = []
 
   def start_file(self):
-    print C_LICENSE_COMMENT + '/** @generated */'
-    print '#define FOR_EACH_CONCRETE_TYPE(MACRO) \\'
+    print(C_LICENSE_COMMENT + '/** @generated */')
+    print('#define FOR_EACH_CONCRETE_TYPE(MACRO) \\')
 
   def start_type(self, name):
     self._types.append(name)
@@ -29,7 +29,7 @@ class Printer(object):
     pass
 
   def end_file(self):
-    print ' \\\n'.join('MACRO(%s, %s)' % (name, snake(name)) for name in self._types)
+    print(' \\\n'.join('MACRO(%s, %s)' % (name, snake(name)) for name in self._types))
 
   def start_union(self, name):
     pass
