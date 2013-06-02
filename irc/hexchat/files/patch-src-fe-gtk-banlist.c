--- src/fe-gtk/banlist.c.orig	2013-04-02 03:07:55.000000000 +0200
+++ src/fe-gtk/banlist.c	2013-04-04 20:31:29.000000000 +0200
@@ -37,6 +37,7 @@
 #include <gtk/gtktreeview.h>
 #include <gtk/gtktreeselection.h>
 #include <gtk/gtktogglebutton.h>
+#include <gtk/gtkcheckbutton.h>
 #include <gtk/gtktable.h>
 #include <glib.h>
 
@@ -583,7 +584,7 @@
  *		#define DATE_FORMAT "%a %b %d %T %Y"
  */
 static void
-strptime (char *ti, struct tm *tm)
+banlist_strptime (char *ti, struct tm *tm)
 {
 	/* Expect something like "Sat Mar 16 21:24:27 2013" */
 	static char *mon[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
@@ -625,8 +626,8 @@
 
 	gtk_tree_model_get(model, a, DATE_COLUMN, &time1, -1);
 	gtk_tree_model_get(model, b, DATE_COLUMN, &time2, -1);
-	strptime (time1, &tm1);
-	strptime (time2, &tm2);
+	banlist_strptime (time1, &tm1);
+	banlist_strptime (time2, &tm2);
 	t1 = mktime (&tm1);
 	t2 = mktime (&tm2);
 
