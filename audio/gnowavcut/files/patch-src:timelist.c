--- src/timelist.c~	Sat Jan 20 17:09:59 2001
+++ src/timelist.c	Tue Apr 23 21:39:09 2002
@@ -87,7 +87,7 @@
 void timelist_end_cb(GtkWidget *widget, gpointer data)
 {
 	GnoWavCut *gnowavcut;
-	int wave_end;
+	guint32 wave_end;
 	gchar *tmp;
   
 	gnowavcut = (GnoWavCut *)data;
@@ -150,7 +150,7 @@
 	GnoWavCut *gnowavcut;
 	gchar *clist_item[2];
 	gchar *tmp;
-	int start, end;
+	guint32 start, end;
 
 	gnowavcut = (GnoWavCut *)data;
 
