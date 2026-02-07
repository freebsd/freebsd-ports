--- ast/cxx_impl.py.orig	2017-10-16 21:39:41 UTC
+++ ast/cxx_impl.py
@@ -12,7 +12,7 @@ class Printer(object):
     pass
 
   def start_file(self):
-    print C_LICENSE_COMMENT + '''/** @generated */
+    print(C_LICENSE_COMMENT + '''/** @generated */
 
 #include "Ast.h"
 #include "AstVisitor.h"
@@ -20,17 +20,17 @@ class Printer(object):
 namespace facebook {
 namespace graphql {
 namespace ast {
-'''
+''')
 
   def end_file(self):
-    print '}'
-    print '}'
-    print '}'
+    print('}')
+    print('}')
+    print('}')
 
   def start_type(self, name):
-    print '''void %s::accept(visitor::AstVisitor *visitor) const {
+    print('''void %s::accept(visitor::AstVisitor *visitor) const {
   if (visitor->visit%s(*this)) {
-''' % (name, name)
+''' % (name, name))
 
   def field(self, type, name, nullable, plural):
     if type in ['OperationKind', 'string', 'boolean']:
@@ -40,18 +40,18 @@ namespace ast {
       accept = '{ for (const auto &x : *%s_) { x->accept(visitor); } }' % name
       if nullable:
         accept = 'if (%s_) %s' % (name, accept)
-      print '    ' + accept
+      print('    ' + accept)
     else:
       accept = '%s_->accept(visitor);' % name
       if nullable:
         accept = 'if (%s_) { %s }' % (name, accept)
-      print '    ' + accept
+      print('    ' + accept)
 
   def end_type(self, name):
-    print '''  }
+    print('''  }
   visitor->endVisit%s(*this);
 }
-''' % name
+''' % name)
 
   def start_union(self, name):
     pass
