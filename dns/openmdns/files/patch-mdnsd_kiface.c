In file included from kiface.c:25:0:
kiface.c:67:1: error: expected ';', identifier or '(' before 'void'
 RB_GENERATE(kif_tree, kif_node, entry, kif_compare)
 ^

--- mdnsd/kiface.c.orig	2015-05-29 14:18:11 UTC
+++ mdnsd/kiface.c
@@ -63,8 +63,8 @@ struct {
 
 
 RB_HEAD(kif_tree, kif_node) kit;
-RB_PROTOTYPE(kif_tree, kif_node, entry, kif_compare)
-RB_GENERATE(kif_tree, kif_node, entry, kif_compare)
+RB_PROTOTYPE(kif_tree, kif_node, entry, kif_compare);
+RB_GENERATE(kif_tree, kif_node, entry, kif_compare);
 
 int
 kif_init(void)
