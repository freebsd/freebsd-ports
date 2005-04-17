--- cliplibs/clip-gtk2/liststore.c.orig	Wed Mar  2 22:27:03 2005
+++ cliplibs/clip-gtk2/liststore.c	Fri Apr 15 13:48:23 2005
@@ -275,9 +275,12 @@
 int
 clip_GTK_LISTSTORESET(ClipMachine * cm)
 {
-	C_object *cslist = _fetch_co_arg(cm);
-        gchar      *path = _clip_parc(cm, 2);
         GtkTreeIter iter;
+	C_object *cslist;
+	gchar      *path;
+
+	path = _clip_parc(cm, 2);
+	cslist = _fetch_co_arg(cm);
 
         CHECKARG2(1, MAP_t, NUMERIC_t);CHECKCOBJ(cslist, GTK_IS_LIST_STORE(cslist->object));
         CHECKARG(2, CHARACTER_t);
@@ -300,10 +303,10 @@
 int
 clip_GTK_LISTSTORESETVALUE(ClipMachine * cm)
 {
-	C_object *cslist = _fetch_co_arg(cm);
-        gchar      *path = _clip_parc(cm, 2);
-        gint	  column = _clip_parni(cm, 3);
-	ClipVar     *val = _clip_par(cm, 4);;
+	C_object *cslist;
+	gchar      *path;
+	gint	  column;
+	ClipVar     *val;
 	GtkTreeIter iter;
         ClipArrVar *utypes;
 	GValue value;
@@ -311,6 +314,11 @@
 	int j;
 	double d;
 
+	cslist = _fetch_co_arg(cm);
+	path =_clip_parc(cm, 2);
+	column = _clip_parni(cm, 3);
+	val = _clip_par(cm, 4);
+
         CHECKARG2(1, MAP_t, NUMERIC_t);CHECKCOBJ(cslist, GTK_IS_LIST_STORE(cslist->object));
         CHECKARG(2, CHARACTER_t);
         CHECKARG(3, NUMERIC_t);
