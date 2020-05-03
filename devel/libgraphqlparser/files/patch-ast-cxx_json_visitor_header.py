--- ast/cxx_json_visitor_header.py.orig	2017-10-16 21:39:41 UTC
+++ ast/cxx_json_visitor_header.py
@@ -13,7 +13,7 @@ class Printer(object):
     self._anyFieldIsANode = False
 
   def start_file(self):
-    print C_LICENSE_COMMENT + '/** @generated */'
+    print(C_LICENSE_COMMENT + '/** @generated */')
 
   def end_file(self):
     pass
@@ -24,9 +24,9 @@ class Printer(object):
   def end_type(self, name):
     titleName = title(name)
     if self._anyFieldIsANode:
-      print 'bool visit%s(const %s &node) override;' % (titleName, titleName)
-    print 'void endVisit%s(const %s &node) override;' % (titleName, titleName)
-    print
+      print('bool visit%s(const %s &node) override;' % (titleName, titleName))
+    print('void endVisit%s(const %s &node) override;' % (titleName, titleName))
+    print()
 
   def field(self, type, name, nullable, plural):
     if (not self._anyFieldIsANode and
