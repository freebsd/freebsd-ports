--- u_smartsearch.h.orig	Tue Jul 26 09:40:00 2005
+++ u_smartsearch.h
@@ -15,9 +15,9 @@
  *
  */
 
-void		init_smart_searchproc_left(int (*handlerproc) (/* ??? */));
-void		init_smart_searchproc_middle(int (*handlerproc) (/* ??? */));
-void		init_smart_searchproc_right(int (*handlerproc) (/* ??? */));
+void		init_smart_searchproc_left(void (*handlerproc) (/* ??? */));
+void		init_smart_searchproc_middle(void (*handlerproc) (/* ??? */));
+void		init_smart_searchproc_right(void (*handlerproc) (/* ??? */));
 
 void		smart_object_search_left(int x, int y, unsigned int shift);
 void		smart_object_search_middle(int x, int y, unsigned int shift);
