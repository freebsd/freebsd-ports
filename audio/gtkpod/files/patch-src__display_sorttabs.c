--- src/display_sorttabs.c.orig	Tue Oct 18 22:25:36 2005
+++ src/display_sorttabs.c	Tue Oct 18 22:26:45 2005
@@ -2036,6 +2036,7 @@
   gint i, n, inst;
   GList *members;
   SortTab *st;
+  T_item t_item;
 
   inst = (guint32)data;
   st = sorttab[inst];
@@ -2093,7 +2094,7 @@
 	      g_return_if_fail (etr);
 	      g_return_if_fail (track->itdb);
 	      if (!itdb) itdb = track->itdb;
-	      T_item t_item = ST_to_T (sorttab[inst]->current_category);
+	      t_item = ST_to_T (sorttab[inst]->current_category);
 	      if (t_item == T_YEAR)
 	      {
 		  gint nr = atoi (new_text);
