--- src/main.c.orig	Thu Jul 27 22:39:02 2006
+++ src/main.c	Thu Jul 27 22:39:28 2006
@@ -41,6 +41,8 @@
   guint _alloc_cnt, _free_cnt, _null_free_cnt;
 #endif
 
+void turtle_init(struct s_turtle *);
+
 
 /*gboolean test(gpointer nil)
 {
