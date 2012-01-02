--- test/lib/sql.py.orig	2011-05-14 12:16:32.000000000 +0000
+++ test/lib/sql.py	2011-12-13 00:23:04.673107891 +0000
@@ -30,8 +30,6 @@
         ('WHERE', re.compile('where')),
         ('VALUES', re.compile('values')),
         ('SET', re.compile('set')),
-        ('OR', re.compile('or')),
-        ('LIMIT', re.compile('limit')),
         ('END', re.compile('\\s*$')),
     ]
     def __init__(self, str,*args,**kw):
@@ -76,16 +74,16 @@
         ident = self.ident(_context)
         SET = self._scan('SET', context=_context)
         update_list = self.update_list(_context)
-        opt_simple_where = self.opt_simple_where(_context)
-        return sql_ast.StatementUpdate(ident, update_list, opt_simple_where)
+        opt_where = self.opt_where(_context)
+        return sql_ast.StatementUpdate(ident, update_list, opt_where)
 
     def delete(self, _parent=None):
         _context = self.Context(_parent, self._scanner, 'delete', [])
         DELETE = self._scan('DELETE', context=_context)
         FROM = self._scan('FROM', context=_context)
         ident = self.ident(_context)
-        opt_simple_where = self.opt_simple_where(_context)
-        return sql_ast.StatementDelete(ident, opt_simple_where)
+        opt_where = self.opt_where(_context)
+        return sql_ast.StatementDelete(ident, opt_where)
 
     def select(self, _parent=None):
         _context = self.Context(_parent, self._scanner, 'select', [])
@@ -94,8 +92,7 @@
         FROM = self._scan('FROM', context=_context)
         ident = self.ident(_context)
         opt_where = self.opt_where(_context)
-        opt_limit = self.opt_limit(_context)
-        return sql_ast.StatementSelect(ident, opt_where, opt_limit)
+        return sql_ast.StatementSelect(ident, opt_where)
 
     def ping(self, _parent=None):
         _context = self.Context(_parent, self._scanner, 'ping', [])
@@ -109,8 +106,8 @@
         constant = self.constant(_context)
         return (ident, constant)
 
-    def opt_simple_where(self, _parent=None):
-        _context = self.Context(_parent, self._scanner, 'opt_simple_where', [])
+    def opt_where(self, _parent=None):
+        _context = self.Context(_parent, self._scanner, 'opt_where', [])
         _token = self._peek('WHERE', 'END', context=_context)
         if _token == 'END':
             return None
@@ -119,38 +116,6 @@
             predicate = self.predicate(_context)
             return predicate
 
-    def opt_where(self, _parent=None):
-        _context = self.Context(_parent, self._scanner, 'opt_where', [])
-        _token = self._peek('WHERE', 'LIMIT', 'END', context=_context)
-        if _token != 'WHERE':
-            return None
-        else: # == 'WHERE'
-            WHERE = self._scan('WHERE', context=_context)
-            disjunction = self.disjunction(_context)
-            return disjunction
-
-    def disjunction(self, _parent=None):
-        _context = self.Context(_parent, self._scanner, 'disjunction', [])
-        predicate = self.predicate(_context)
-        disjunction = [predicate]
-        if self._peek('OR', 'LIMIT', 'END', context=_context) == 'OR':
-            while 1:
-                OR = self._scan('OR', context=_context)
-                predicate = self.predicate(_context)
-                disjunction.append(predicate)
-                if self._peek('OR', 'LIMIT', 'END', context=_context) != 'OR': break
-        return disjunction
-
-    def opt_limit(self, _parent=None):
-        _context = self.Context(_parent, self._scanner, 'opt_limit', [])
-        _token = self._peek('LIMIT', 'END', context=_context)
-        if _token == 'END':
-            return 0xffffffff
-        else: # == 'LIMIT'
-            LIMIT = self._scan('LIMIT', context=_context)
-            NUM = self._scan('NUM', context=_context)
-            return int(NUM)
-
     def value_list(self, _parent=None):
         _context = self.Context(_parent, self._scanner, 'value_list', [])
         self._scan("'\\('", context=_context)
