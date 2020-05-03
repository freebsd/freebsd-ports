--- ast/js.py.orig	2017-10-16 21:39:41 UTC
+++ ast/js.py
@@ -11,7 +11,7 @@ class Printer(object):
     pass
 
   def start_file(self):
-    print '''/* @flow */
+    print('''/* @flow */
 /* @generated */
 /* jshint ignore:start */
 
@@ -30,21 +30,21 @@ type Node = {
   end?: ?number;
 };
 
-type OperationKind = 'query' | 'mutation' | 'subscription';'''
+type OperationKind = 'query' | 'mutation' | 'subscription';''')
 
   def end_file(self):
     pass
 
   def start_type(self, name):
-    print
-    print 'type %s = Node & {' % name
+    print()
+    print('type %s = Node & {' % name)
     kind = name
     if kind == 'GenericType':
       kind = 'Type'
-    print '  kind: \'%s\';' % kind
+    print('  kind: \'%s\';' % kind)
 
   def end_type(self, name):
-    print '}'
+    print('}')
 
   def _js_type(self, type, plural):
     if plural:
@@ -54,16 +54,16 @@ type OperationKind = 'query' | 'mutation' | 'subscript
   def field(self, type, name, nullable, plural):
     nullable_char = '?' if nullable else ''
     js_type = self._js_type(type, plural)
-    print '  %(name)s%(nullable_char)s: %(nullable_char)s%(js_type)s;' % locals()
+    print('  %(name)s%(nullable_char)s: %(nullable_char)s%(js_type)s;' % locals())
 
   def start_union(self, name):
-    print ('type %s = ' % name),
+    print(('type %s = ' % name), end=' ')
     self._current_options = []
 
   def union_option(self, type):
     self._current_options.append(type)
 
   def end_union(self, name):
-    print '\n  | '.join(self._current_options)
-    print
+    print('\n  | '.join(self._current_options))
+    print()
     self._current_options = None
