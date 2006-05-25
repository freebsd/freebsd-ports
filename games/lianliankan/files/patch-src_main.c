--- src/main.c.orig	Wed Dec  7 05:15:14 2005
+++ src/main.c	Thu May 25 00:52:58 2006
@@ -727,9 +727,9 @@
     /* get and set next card back, and get and set next background picture */
     ui_pixbuf.cardback_choice = ui_pixbuf.cardback_choice>=5?0:ui_pixbuf.cardback_choice+1;
     if(pak_info.back_num > 0){
+      gchar bgfilename[30];
       ui_pixbuf.randomback_choice = ui_pixbuf.randomback_choice>pak_info.back_num-1?1:ui_pixbuf.randomback_choice+1;
       /* Extract the bg picture and read it to ui_pixbuf.randomback */
-      gchar bgfilename[30];
       sprintf(bgfilename,"back%d.jpg",ui_pixbuf.randomback_choice-1);
       if(!ExtractSingleFile(bgfilename)){g_print(_("Failed to extract file:%s.\n"),bgfilename);}
       sprintf(bgfilename,"/tmp/llk_back%d.jpg",ui_pixbuf.randomback_choice-1);
@@ -1200,12 +1200,13 @@
   struct passwd *user;
   int result;
   char path[MAX_PATH_LENGTH];
-  *message = (gchar *)g_malloc(sizeof(gchar)*100);
   gchar *return_str;
   GSList *radio_item_group=NULL;
   GtkWidget *menu,*menuitem;
   gint i;
 
+  *message = (gchar *)g_malloc(sizeof(gchar)*100);
+
   /* load ini file,if it do not exist, make a new one */
   user = getpwuid(getuid());
   /*user home directory: user->pw_dir*/
@@ -1352,9 +1353,9 @@
   ui_pixbuf.mainback   = gdk_pixbuf_new_from_file("/tmp/llk_mainback.jpg",NULL);
   ui_pixbuf.cardback_choice = g_rand_int_range(ui_rand,0,6); /*begin to end-1*/
   if(pak_info.back_num > 0){
+    gchar bgfilename[30];
     ui_pixbuf.randomback_choice = g_rand_int_range(ui_rand,1,pak_info.back_num+1);
     /* Extract the bg picture and read it to ui_pixbuf.randomback */
-    gchar bgfilename[30];
     sprintf(bgfilename,"back%d.jpg",ui_pixbuf.randomback_choice-1);
     if(!ExtractSingleFile(bgfilename)){g_print(_("Failed to extract file:%s.\n"),bgfilename);}
     sprintf(bgfilename,"/tmp/llk_back%d.jpg",ui_pixbuf.randomback_choice-1);
@@ -1474,9 +1475,9 @@
           ui_pixbuf.mainback   = gdk_pixbuf_new_from_file("/tmp/llk_mainback.jpg",NULL);
           /* ui_pixbuf.cardback_choice = g_rand_int_range(ui_rand,0,6);*//*Do not change card back choice when change theme*/
           if(pak_info.back_num > 0){
+              gchar bgfilename[30];
               ui_pixbuf.randomback_choice = g_rand_int_range(ui_rand,1,pak_info.back_num+1);
               /* Extract the bg picture and read it to ui_pixbuf.randomback */
-              gchar bgfilename[30];
               sprintf(bgfilename,"back%d.jpg",ui_pixbuf.randomback_choice-1);
               if(!ExtractSingleFile(bgfilename)){g_print(_("Failed to extract file:%s.\n"),bgfilename);}
               sprintf(bgfilename,"/tmp/llk_back%d.jpg",ui_pixbuf.randomback_choice-1);
@@ -1640,6 +1641,12 @@
   gchar path[MAX_PATH_LENGTH];
   struct ScoreItem *score_list=NULL,*score_item_end=NULL,*score_item_tmp;
   gint item_num=0;
+
+  GtkWidget *dialog,*tree_view,*button;
+  GtkCellRenderer *renderer;
+  GtkListStore  *store;
+  GtkTreeIter    iter;
+
   /* load ini file,if it do not exist, make a new one */
   user = getpwuid(getuid());
   /*user home directory: user->pw_dir*/
@@ -1676,6 +1683,7 @@
   if(!view) /* If not just view the score,then this function must be called by ui_game_over,so add the current player's score
                into the list,and then write to file if the list is modified,and at last,show the score list on a new window */
   {
+    time_t t;
     gint insert_pos=1;
     for(score_item_tmp = score_list;score_item_tmp!=NULL;score_item_tmp=score_item_tmp->next)
     {
@@ -1748,7 +1756,6 @@
              break;
     }
     sprintf(score_item_tmp->level,"%d",algorithm_game.level);
-    time_t t;
     time(&t);
     sprintf(score_item_tmp->time,"%s",asctime(gmtime(&t)));
     ui_input_string(score_item_tmp->name,score_item_tmp->nick,50);
@@ -1775,10 +1782,6 @@
     }
   }
   /* Create a new window to show scores. */
-  GtkWidget *dialog,*tree_view,*button;
-  GtkCellRenderer *renderer;
-  GtkListStore  *store;
-  GtkTreeIter    iter;
   dialog = gtk_dialog_new();
   gtk_window_set_title(GTK_WINDOW(dialog),_("Top 10 Heros"));
   gtk_container_border_width(GTK_CONTAINER(dialog),5);
