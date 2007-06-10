--- u_search.h.orig	Tue Jul 26 09:40:00 2005
+++ u_search.h
@@ -20,9 +20,9 @@
 
 Boolean		in_text_bound(F_text *t, int x, int y, int *posn, Boolean extra);
 
-void		init_searchproc_left(int (*handlerproc) (/* ??? */));
-void		init_searchproc_middle(int (*handlerproc) (/* ??? */));
-void		init_searchproc_right(int (*handlerproc) (/* ??? */));
+void		init_searchproc_left(void (*handlerproc) (/* ??? */));
+void		init_searchproc_middle(void (*handlerproc) (/* ??? */));
+void		init_searchproc_right(void (*handlerproc) (/* ??? */));
 
 void		point_search_left(int x, int y, unsigned int shift);
 void		point_search_middle(int x, int y, unsigned int shift);
