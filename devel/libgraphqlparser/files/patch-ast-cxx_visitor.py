--- ast/cxx_visitor.py.orig	2017-10-16 21:39:41 UTC
+++ ast/cxx_visitor.py
@@ -13,7 +13,7 @@ class Printer(object):
     pass
 
   def start_file(self):
-    print C_LICENSE_COMMENT + '''/** @generated */
+    print(C_LICENSE_COMMENT + '''/** @generated */
 
 #pragma once
 
@@ -27,28 +27,28 @@ namespace visitor {
 class AstVisitor {
 public:
   virtual ~AstVisitor() {}
-'''
+''')
 
   def end_file(self):
-    print '};' # end AstVisitor
-    print
-    print '}'
-    print '}'
-    print '}'
-    print '}'
+    print('};') # end AstVisitor
+    print()
+    print('}')
+    print('}')
+    print('}')
+    print('}')
 
   def start_type(self, name):
     titleName = title(name)
     camelName = camel(titleName)
-    print '  virtual bool visit%s(const %s &%s) { return true; }' % (
+    print('  virtual bool visit%s(const %s &%s) { return true; }' % (
       titleName,
       titleName,
-      camelName)
-    print '  virtual void endVisit%s(const %s &%s) { }' % (
+      camelName))
+    print('  virtual void endVisit%s(const %s &%s) { }' % (
       titleName,
       titleName,
-      camelName)
-    print
+      camelName))
+    print()
 
   def end_type(self, name):
     pass
