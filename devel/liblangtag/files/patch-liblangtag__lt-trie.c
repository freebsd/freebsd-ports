--- liblangtag/lt-trie.c.orig	2013-04-29 22:37:30.000000000 -0400
+++ liblangtag/lt-trie.c	2013-05-07 18:52:21.000000000 -0400
@@ -33,11 +33,11 @@
 	lt_iter_tmpl_t  parent;
 	lt_trie_node_t *root;
 };
-typedef struct _lt_trie_iter_t {
+struct _lt_trie_iter_t {
 	lt_iter_t    parent;
 	lt_list_t   *stack;
 	lt_string_t *pos_str;
-} lt_trie_iter_t;
+};
 
 /*< private >*/
 static lt_trie_node_t *
