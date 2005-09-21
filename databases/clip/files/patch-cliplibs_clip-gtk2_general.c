--- cliplibs/clip-gtk2/general.c.orig	Sun Sep 18 15:19:32 2005
+++ cliplibs/clip-gtk2/general.c	Sun Sep 18 15:27:53 2005
@@ -605,6 +605,12 @@
 int
 clip_G_OBJECTGET(ClipMachine * cm)
 {
+        GObject  *gobj ;
+        gint         i ;
+        gboolean     b ;
+        gchar       *c ;
+        gdouble      d ;
+        
 	C_widget *cwid = _fetch_cw_arg(cm);
 	C_object *cobj = _fetch_co_arg(cm);
         gchar    *name = _clip_parc(cm, 2);
@@ -612,12 +618,6 @@
 
 	CHECKARG(2, CHARACTER_t);
         CHECKARG(3, NUMERIC_t);
-
-        GObject  *gobj ;
-        gint         i ;
-        gboolean     b ;
-        gchar       *c ;
-        gdouble      d ;
 
 	if (cwid->objtype == GTK_OBJ_WIDGET)
         	gobj = G_OBJECT(cwid->widget);
