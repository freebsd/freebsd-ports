--- libs/spirit/example/application/slex/lexer.hpp.orig	Fri Oct 15 11:57:49 2004
+++ libs/spirit/example/application/slex/lexer.hpp	Fri Oct 15 11:58:01 2004
@@ -2108,7 +2108,7 @@
             s = dfa.transition_table[s][(uchar)*p];
             if (s == invalid_node)
                 break;
-            if (token) token->append((string_t::size_type)1, *p);
+            if (token) token->append((typename string_t::size_type)1, *p);
             ++p;
             if (dfa.acceptance_index[s] != invalid_node)
             {
@@ -2163,7 +2163,7 @@
                     goto break_while;
                 }
             }
-            if (token) token->append((string_t::size_type)1, *wp);
+            if (token) token->append((typename string_t::size_type)1, *wp);
             ++wp;
             if (dfa.acceptance_index[s] != invalid_node)
             {
