--- prcg.prototypes.h.orig	1994-11-14 03:32:00.000000000 +0800
+++ prcg.prototypes.h	2011-09-16 09:27:00.000000000 +0800
@@ -8,9 +8,9 @@ struct imm_node *link_arc_node(char *s, 
 struct name_node *name_to_nlist(char *s, char *t);
 struct imm_node *node_to_arc(struct name_node *np, struct imm_node *ip);
 static struct imm_node *get_imm_node(void);
-int print_dcg(int argc, char **argv);
-int print_name(struct name_node *node, int tabc);
+void print_dcg(int argc, char **argv);
+void print_name(struct name_node *node, int tabc);
 int makeactive(struct name_node *node);
-int backup(void);
+void backup(void);
 int active(struct name_node *node);
 struct name_node *nlist_contains(char *s);
