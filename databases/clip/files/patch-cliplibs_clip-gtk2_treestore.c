--- cliplibs/clip-gtk2/treestore.c.orig	Tue Apr 19 21:12:14 2005
+++ cliplibs/clip-gtk2/treestore.c	Thu Jun  2 17:40:59 2005
@@ -322,10 +322,10 @@
 int
 clip_GTK_TREESTORESETVALUE(ClipMachine * cm)
 {
-	C_object *cstree = _fetch_co_arg(cm);
-        gchar      *path = _clip_parc(cm, 2);
-        gint	  column = _clip_parni(cm, 3);
-	ClipVar     *val = _clip_par(cm, 4);;
+	C_object *cstree;
+        gchar      *path;
+        gint	  column;
+	ClipVar     *val;
 	GtkTreeIter iter;
         ClipArrVar *utypes;
 	GValue value;
@@ -333,6 +333,11 @@
 	gchar *str;
 	int j,n;
 	double d;
+
+	cstree = _fetch_co_arg(cm);
+        path = _clip_parc(cm, 2);
+        column = _clip_parni(cm, 3);
+	val = _clip_par(cm, 4);;
 
         CHECKARG2(1, MAP_t, NUMERIC_t);CHECKCOBJ(cstree, GTK_IS_TREE_STORE(cstree->object));
         CHECKARG(2, CHARACTER_t);
