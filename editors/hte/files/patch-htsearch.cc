$FreeBSD$

--- htsearch.cc.orig	Fri Jun  7 22:20:50 2002
+++ htsearch.cc	Fri Jun  7 22:20:58 2002
@@ -780,7 +780,7 @@
  *	CLASS ht_expr_search_form
  */
 
-void	ht_expr_search_form::init(bounds *b, int options, ht_list *history=0)
+void	ht_expr_search_form::init(bounds *b, int options, ht_list *history)
 {
 	ht_group::init(b, VO_SELECTABLE, NULL);
 	VIEW_DEBUG_NAME("ht_expr_search_form");
