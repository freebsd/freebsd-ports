--- ./cliplibs/clip-gtk2/treestore.c.orig	Tue Apr 19 13:12:14 2005
+++ ./cliplibs/clip-gtk2/treestore.c	Wed Apr 19 23:03:56 2006
@@ -325,7 +325,7 @@
 	C_object *cstree = _fetch_co_arg(cm);
         gchar      *path = _clip_parc(cm, 2);
         gint	  column = _clip_parni(cm, 3);
-	ClipVar     *val = _clip_par(cm, 4);;
+	ClipVar     *val = _clip_par(cm, 4);
 	GtkTreeIter iter;
         ClipArrVar *utypes;
 	GValue value;
