--- ast/cxx_json_visitor_impl.py.orig	2017-10-16 21:39:41 UTC
+++ ast/cxx_json_visitor_impl.py
@@ -13,7 +13,7 @@ class Printer(object):
     self._fields = []
 
   def start_file(self):
-    print C_LICENSE_COMMENT + '/** @generated */'
+    print(C_LICENSE_COMMENT + '/** @generated */')
 
   def end_file(self):
     pass
@@ -31,13 +31,13 @@ class Printer(object):
     anyFieldIsANode = any(type not in ('string, boolean')
                           for (type, _, _ ,_) in self._fields)
     if anyFieldIsANode:
-      print '''bool JsonVisitor::visit%s(const %s &node) {
+      print('''bool JsonVisitor::visit%s(const %s &node) {
   visitNode();
   return true;
 }
-''' % (titleName, titleName)
-    print '''void JsonVisitor::endVisit%(tn)s(const %(tn)s &node) {
-  NodeFieldPrinter fields(*this, "%(tn)s", node);''' % {'tn': titleName}
+''' % (titleName, titleName))
+    print('''void JsonVisitor::endVisit%(tn)s(const %(tn)s &node) {
+  NodeFieldPrinter fields(*this, "%(tn)s", node);''' % {'tn': titleName})
 
     for (type, fieldName, nullable, plural) in self._fields:
       funcName = None
@@ -49,7 +49,7 @@ class Printer(object):
         funcName = 'printSingularBooleanField'
       elif not nullable and not plural:
         # Special case: singular object fields don't need the value passed.
-        print '  fields.printSingularObjectField("%s");' % fieldName
+        print('  fields.printSingularObjectField("%s");' % fieldName)
         continue
       else:
         nullable_str = 'Nullable' if nullable else ''
@@ -57,19 +57,19 @@ class Printer(object):
         funcName = 'print%s%sField' % (nullable_str, plural_str)
 
       assert funcName is not None
-      print '  fields.%s("%s", node.get%s());' % (
-        funcName, fieldName, title(fieldName))
+      print('  fields.%s("%s", node.get%s());' % (
+        funcName, fieldName, title(fieldName)))
 
     if anyFieldIsANode:
-      print '''
+      print('''
   endVisitNode(fields.finishPrinting());
 }
-'''
+''')
     else:
-      print '''
+      print('''
   printed_.back().emplace_back(fields.finishPrinting());
 }
-'''
+''')
 
   def start_union(self, name):
     pass
