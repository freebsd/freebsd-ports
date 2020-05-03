--- ast/c.py.orig	2017-10-16 21:39:41 UTC
+++ ast/c.py
@@ -62,7 +62,7 @@ class Printer(object):
     self._current_type = None
 
   def start_file(self):
-    print C_LICENSE_COMMENT + '''/** @generated */
+    print(C_LICENSE_COMMENT + '''/** @generated */
 
 #pragma once
 
@@ -70,33 +70,33 @@ class Printer(object):
 extern "C" {
 #endif
 
-'''
+''')
 
   def end_file(self):
-    print '''
+    print('''
 
 #ifdef __cplusplus
 }
 #endif
-'''
+''')
 
   def start_type(self, name):
     # Forward declarations for AST nodes.
     st_name = struct_name(name)
-    print 'struct ' + st_name + ';'
+    print('struct ' + st_name + ';')
     self._current_type = name
 
   def field(self, type, name, nullable, plural):
-    print field_prototype(self._current_type, type, name, nullable, plural) + ';'
+    print(field_prototype(self._current_type, type, name, nullable, plural) + ';')
 
   def end_type(self, name):
-    print
+    print()
 
   def start_union(self, name):
-    print 'struct ' + struct_name(name) + ';'
+    print('struct ' + struct_name(name) + ';')
 
   def union_option(self, option):
     pass
 
   def end_union(self, name):
-    print
+    print()
