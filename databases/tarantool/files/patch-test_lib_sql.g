--- test/lib/sql.g.orig	2011-05-14 12:16:32.000000000 +0000
+++ test/lib/sql.g	2011-12-13 00:41:37.729004939 +0000
@@ -5,10 +5,6 @@
 
 %%
 
-# The grammar below solely covers the functionality provided by
-# Tarantool binary protocol, from which follow all the
-# limitations. For reference please see doc/box-protocol.txt.
-
 parser sql:
 
     ignore:           '\\s+'
@@ -25,8 +21,6 @@
     token WHERE:      'where'
     token VALUES:     'values'
     token SET:        'set'
-    token OR:         'or'
-    token LIMIT:      'limit'
     token END:        '\\s*$'
 
     rule sql:         (insert {{ stmt = insert }} |
@@ -37,27 +31,19 @@
                       
     rule insert:      INSERT [INTO] ident VALUES value_list
                       {{ return sql_ast.StatementInsert(ident, value_list) }}
-    rule update:      UPDATE ident SET update_list opt_simple_where
-                      {{ return sql_ast.StatementUpdate(ident, update_list, opt_simple_where) }}
-    rule delete:      DELETE FROM ident opt_simple_where
-                      {{ return sql_ast.StatementDelete(ident, opt_simple_where) }}
-    rule select:      SELECT '\*' FROM ident opt_where opt_limit
-                      {{ return sql_ast.StatementSelect(ident, opt_where, opt_limit) }}
+    rule update:      UPDATE ident SET update_list opt_where 
+                      {{ return sql_ast.StatementUpdate(ident, update_list, opt_where) }}
+    rule delete:      DELETE FROM ident opt_where
+                      {{ return sql_ast.StatementDelete(ident, opt_where) }}
+    rule select:      SELECT '\*' FROM ident opt_where
+                      {{ return sql_ast.StatementSelect(ident, opt_where) }}
     rule ping:        PING
                       {{ return sql_ast.StatementPing() }}
     rule predicate:   ident '=' constant
                       {{ return (ident, constant) }}
-    rule opt_simple_where:   {{ return None }}
+    rule opt_where:   {{ return None }}
                       | WHERE predicate
                       {{ return predicate }}
-    rule opt_where:   {{ return None }}
-                      | WHERE disjunction
-                      {{ return disjunction }}
-    rule disjunction: predicate {{ disjunction = [predicate] }}
-                      [(OR predicate {{ disjunction.append(predicate) }})+]
-                      {{ return disjunction }}
-    rule opt_limit:   {{ return 0xffffffff }}
-                      | LIMIT NUM {{ return int(NUM) }}
     rule value_list:  '\(' expr {{ value_list = [expr] }}
                           [("," expr {{ value_list.append(expr) }} )+]
                       '\)' {{ return value_list }}
