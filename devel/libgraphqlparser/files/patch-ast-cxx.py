--- ast/cxx.py.orig	2017-10-16 21:39:41 UTC
+++ ast/cxx.py
@@ -5,7 +5,7 @@
 # LICENSE file in the root directory of this source tree. An additional grant
 # of patent rights can be found in the PATENTS file in the same directory.
 
-import cStringIO as StringIO
+import io as StringIO
 
 from casing import title
 from license import C_LICENSE_COMMENT
@@ -23,7 +23,7 @@ class Printer(object):
     self._fields = []
 
   def start_file(self):
-    print C_LICENSE_COMMENT + '''/** @generated */
+    print(C_LICENSE_COMMENT + '''/** @generated */
 #pragma once
 
 #include "AstNode.h"
@@ -42,14 +42,14 @@ namespace ast {
 struct CDeleter {
   void operator()(const char *p) const { free((void *)p); }
 };
-'''
+''')
 
   def end_file(self):
-    print
-    print self._deferredOutput.getvalue()
-    print '}'
-    print '}'
-    print '}'
+    print()
+    print(self._deferredOutput.getvalue())
+    print('}')
+    print('}')
+    print('}')
 
   def _base_class(self, type):
     return self._bases.get(type, 'Node')
@@ -58,8 +58,8 @@ struct CDeleter {
     self._type_name = name
     base = self._base_class(name)
     # non-deferred!
-    print 'class %s;' % name
-    print >> self._deferredOutput, 'class %s : public %s {' % (name, base)
+    print('class %s;' % name)
+    print('class %s : public %s {' % (name, base), file=self._deferredOutput)
     self._fields = []
 
   def field(self, type, name, nullable, plural):
@@ -69,18 +69,18 @@ struct CDeleter {
 
   def end_type(self, name):
     self._print_fields()
-    print >> self._deferredOutput, ' public:'
+    print(' public:', file=self._deferredOutput)
     self._print_constructor()
-    print >> self._deferredOutput
+    print(file=self._deferredOutput)
     self._print_destructor_prototype()
-    print >> self._deferredOutput
+    print(file=self._deferredOutput)
     self._print_noncopyable()
-    print >> self._deferredOutput
+    print(file=self._deferredOutput)
     self._print_getters()
-    print >> self._deferredOutput, '  void accept(visitor::AstVisitor *visitor) const override;'
-    print >> self._deferredOutput, '};'
-    print >> self._deferredOutput
-    print >> self._deferredOutput
+    print('  void accept(visitor::AstVisitor *visitor) const override;', file=self._deferredOutput)
+    print('};', file=self._deferredOutput)
+    print(file=self._deferredOutput)
+    print(file=self._deferredOutput)
     self._type_name = None
     self._fields = []
 
@@ -97,7 +97,7 @@ struct CDeleter {
       storage_type = self._storage_type(type)
       if plural:
         storage_type = 'std::unique_ptr<std::vector<%s>>' % storage_type
-      print >> self._deferredOutput, '  %s %s_;' % (storage_type, name)
+      print('  %s %s_;' % (storage_type, name), file=self._deferredOutput)
 
   def _ctor_singular_type(self, type):
     if type == 'string':
@@ -111,28 +111,28 @@ struct CDeleter {
     return 'std::vector<%s> *' % self._storage_type(type)
 
   def _print_constructor(self):
-    print >> self._deferredOutput, '  explicit %s(' % self._type_name
-    print >> self._deferredOutput, '      const yy::location &location%s' % (',' if self._fields else '')
+    print('  explicit %s(' % self._type_name, file=self._deferredOutput)
+    print('      const yy::location &location%s' % (',' if self._fields else ''), file=self._deferredOutput)
     def ctor_arg(type, name, plural):
       if plural:
         ctor_type = self._ctor_plural_type(type)
       else:
         ctor_type = self._ctor_singular_type(type)
       return '      %s %s' % (ctor_type, name)
-    print >> self._deferredOutput, ',\n'.join(ctor_arg(type, name, plural)
-                     for (type, name, nullable, plural) in self._fields)
-    print >> self._deferredOutput, '  )'
+    print(',\n'.join(ctor_arg(type, name, plural)
+                     for (type, name, nullable, plural) in self._fields), file=self._deferredOutput)
+    print('  )', file=self._deferredOutput)
     def ctor_init(type, name, plural):
       # Strings are const char *, just pass.
       # Vectors are passed by pointer and we take ownership.
       # Node types are passed in by pointer and we take ownership.
       value = name
       return '    %s_(%s)' % (name, value)
-    print >> self._deferredOutput, '  : %s(location)%s' % (self._base_class(self._type_name), ',' if self._fields else '')
-    print >> self._deferredOutput, ',\n'.join(ctor_init(type, name, plural)
+    print('  : %s(location)%s' % (self._base_class(self._type_name), ',' if self._fields else ''), file=self._deferredOutput)
+    print(',\n'.join(ctor_init(type, name, plural)
                      for (type, name, nullable, plural)
-                     in self._fields)
-    print >> self._deferredOutput, '  {}'
+                     in self._fields), file=self._deferredOutput)
+    print('  {}', file=self._deferredOutput)
 
   def _getter_type(self, type, nullable, plural):
     if plural and nullable:
@@ -165,31 +165,31 @@ struct CDeleter {
 
   def _print_getters(self):
     for (type, name, nullable, plural) in self._fields:
-      print >> self._deferredOutput, '  %s get%s() const' % (
+      print('  %s get%s() const' % (
         self._getter_type(type, nullable, plural),
-        title(name))
-      print >> self._deferredOutput, '  { return %s; }' % (
-        self._getter_value_to_return(name + '_', type, nullable, plural))
-      print >> self._deferredOutput
+        title(name)), file=self._deferredOutput)
+      print('  { return %s; }' % (
+        self._getter_value_to_return(name + '_', type, nullable, plural)), file=self._deferredOutput)
+      print(file=self._deferredOutput)
 
   def _print_destructor_prototype(self):
-    print >> self._deferredOutput, '  ~%s() {}' % self._type_name
+    print('  ~%s() {}' % self._type_name, file=self._deferredOutput)
 
   def _print_noncopyable(self):
-    print >> self._deferredOutput, '  %s(const %s&) = delete;' % (
-      self._type_name, self._type_name)
-    print >> self._deferredOutput, '  %s& operator=(const %s&) = delete;' % (
-      self._type_name, self._type_name)
+    print('  %s(const %s&) = delete;' % (
+      self._type_name, self._type_name), file=self._deferredOutput)
+    print('  %s& operator=(const %s&) = delete;' % (
+      self._type_name, self._type_name), file=self._deferredOutput)
   
   def start_union(self, name):
     self._type_name = name
     # non-deferred!
-    print 'class %s;' % name
-    print >> self._deferredOutput, 'class %s : public Node {' % name
-    print >> self._deferredOutput, ' public:'
+    print('class %s;' % name)
+    print('class %s : public Node {' % name, file=self._deferredOutput)
+    print(' public:', file=self._deferredOutput)
     self._print_constructor()
-    print >> self._deferredOutput, '};'
-    print >> self._deferredOutput
+    print('};', file=self._deferredOutput)
+    print(file=self._deferredOutput)
 
   def union_option(self, type):
     assert type not in self._bases, '%s cannot appear in more than one union!' % type
