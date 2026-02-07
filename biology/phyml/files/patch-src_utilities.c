--- src/utilities.c.orig	2022-04-08 15:01:10 UTC
+++ src/utilities.c
@@ -3209,18 +3209,20 @@ void Bootstrap(t_tree *tree)
       boot_tree->io->print_json_trace = NO;
       boot_tree->n_root               = NULL;
       boot_tree->e_root               = NULL;
+      boot_tree->l_ev                 = tree->l_ev;
+      boot_tree->p_lk_left_pi         = tree->p_lk_left_pi;
+
+#if (defined(__AVX__) || defined(__AVX2__) || defined(__SSE__) || defined(__SSE2__) || defined(__SSE3__))
       boot_tree->_tPij1               = tree->_tPij1;
       boot_tree->_tPij2               = tree->_tPij2;
       boot_tree->_pmat1plk1           = tree->_pmat1plk1;
       boot_tree->_pmat2plk2           = tree->_pmat2plk2;
       boot_tree->_plk0                = tree->_plk0;
-      boot_tree->l_ev                 = tree->l_ev;
-      boot_tree->p_lk_left_pi         = tree->p_lk_left_pi;
       boot_tree->_l_ev                = tree->_l_ev;
       boot_tree->_r_ev                = tree->_r_ev;
       boot_tree->_prod_left           = tree->_prod_left;
       boot_tree->_prod_rght           = tree->_prod_rght;
-      
+#endif
 
       Set_Both_Sides(YES,boot_tree);
 
@@ -8902,7 +8904,7 @@ t_edge *Find_Root_Edge(FILE *fp_input_tree, t_tree *tr
   int l_r, r_l;
   int score;
   char *line;
-  char c;
+  int c;
   t_edge *root_edge;
 
   line = (char *)mCalloc(T_MAX_LINE,sizeof(char));
@@ -9206,7 +9208,7 @@ void Translate_Tax_Names(char **tax_names, t_tree *tre
 void Skip_Comment(FILE *fp)
 {
   int in_comment;
-  char c;
+  int c;
 
   in_comment = 1;
   do
