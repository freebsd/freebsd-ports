--- ast/c_impl.py.orig	2017-10-16 21:39:41 UTC
+++ ast/c_impl.py
@@ -17,13 +17,13 @@ class Printer(object):
     self._current_type = None
 
   def start_file(self):
-    print C_LICENSE_COMMENT + '''/** @generated */
+    print(C_LICENSE_COMMENT + '''/** @generated */
 
 #include "GraphQLAst.h"
 #include "../Ast.h"
 
 using namespace facebook::graphql::ast;
-'''
+''')
 
   def end_file(self):
     pass
@@ -32,23 +32,23 @@ using namespace facebook::graphql::ast;
     self._current_type = name
 
   def field(self, type, name, nullable, plural):
-    print field_prototype(self._current_type, type, name, nullable, plural) + ' {'
-    print '  const auto *realNode = (const %s *)node;' % self._current_type
+    print(field_prototype(self._current_type, type, name, nullable, plural) + ' {')
+    print('  const auto *realNode = (const %s *)node;' % self._current_type)
     title_name = title(name)
     call_get = 'realNode->get%s()' % title_name
     if plural:
       if nullable:
-        print '  return %s ? %s->size() : 0;' % (call_get, call_get)
+        print('  return %s ? %s->size() : 0;' % (call_get, call_get))
       else:
-        print '  return %s.size();' % call_get
+        print('  return %s.size();' % call_get)
     else:
       if type in ['string', 'OperationKind', 'boolean']:
-        print '  return %s;' % call_get
+        print('  return %s;' % call_get)
       else:
         fmt = '  return (const struct %s *)%s%s;'
-        print fmt % (struct_name(type), '' if nullable else '&', call_get)
+        print(fmt % (struct_name(type), '' if nullable else '&', call_get))
 
-    print '}'
+    print('}')
 
   def end_type(self, name):
     pass
