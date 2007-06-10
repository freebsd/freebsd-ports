--- u_smartsearch.c.orig	Tue Jul 26 09:40:00 2005
+++ u_smartsearch.c
@@ -51,10 +51,10 @@
 F_point  smart_point1, smart_point2;
 
 /* locals: */
-static int	(*manipulate) ();
-static int	(*handlerproc_left) ();
-static int	(*handlerproc_middle) ();
-static int	(*handlerproc_right) ();
+static void	(*manipulate) ();
+static void	(*handlerproc_left) ();
+static void	(*handlerproc_middle) ();
+static void	(*handlerproc_right) ();
 static int	type;
 static long	objectcount;
 static long	n;
@@ -74,19 +74,19 @@
 
 
 void
-init_smart_searchproc_left(int (*handlerproc) (/* ??? */))
+init_smart_searchproc_left(void (*handlerproc) (/* ??? */))
 {
     handlerproc_left = handlerproc;
 }
 
 void
-init_smart_searchproc_middle(int (*handlerproc) (/* ??? */))
+init_smart_searchproc_middle(void (*handlerproc) (/* ??? */))
 {
     handlerproc_middle = handlerproc;
 }
 
 void
-init_smart_searchproc_right(int (*handlerproc) (/* ??? */))
+init_smart_searchproc_right(void (*handlerproc) (/* ??? */))
 {
     handlerproc_right = handlerproc;
 }
