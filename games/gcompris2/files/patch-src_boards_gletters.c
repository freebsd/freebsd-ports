--- src/boards/gletters.c.orig	Tue Nov 30 04:16:40 2004
+++ src/boards/gletters.c	Tue Nov 30 04:18:51 2004
@@ -690,9 +690,9 @@
   GnomeCanvasItem *item;
   gchar *str  = NULL;
   gchar *str2 = NULL;
-  gint i,j,k;
+  gint i,j,k,attempt;
   guint c, x;
-  gchar *lettersItem, *str_p;
+  gchar *lettersItem, *str_p, *letter_no_caps;
 
   if (!letters_table)
     {
@@ -709,7 +709,7 @@
   k=g_utf8_strlen(letters_array[gcomprisBoard->level-1],-1);
 
   lettersItem = g_new(gchar,6);
-  gint attempt=0;
+  attempt=0;
   do {
 
     attempt++;
@@ -726,7 +726,7 @@
 
   if (item_find_by_title(lettersItem)!=NULL)  {g_free(lettersItem); return NULL;}
 
-  gchar *letter_no_caps=g_utf8_strdown(lettersItem,-1);
+  letter_no_caps=g_utf8_strdown(lettersItem,-1);
   str = g_strdup_printf("%s%s", letter_no_caps, ".ogg");
   str2 = gcompris_get_asset_file("gcompris alphabet", NULL, "audio/x-ogg", str);
   gcompris_play_ogg(str2, NULL);
