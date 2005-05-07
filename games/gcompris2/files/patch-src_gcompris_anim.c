--- src/gcompris/anim.c.orig	Sat May  7 00:02:54 2005
+++ src/gcompris/anim.c	Sat May  7 00:04:16 2005
@@ -33,6 +33,14 @@ static gboolean anim_tick(void*);
 GcomprisAnimation *gcompris_load_animation(char *filename)
 {
   FILE *f;
+  char tmp[100];
+  GSList *files = NULL;
+  GcomprisAnimation *anim = NULL;
+  /* open the animations and assign them */
+  GError *error = NULL;
+  GSList *cur;
+  char *name;
+  int i;
   if(filename[0] == '/')  /* we were probably called by load_animation_asset */
     {
       f = fopen(filename, "r");
@@ -50,9 +58,6 @@ GcomprisAnimation *gcompris_load_animati
       return NULL;
     }
 
-  char tmp[100];
-  GSList *files = NULL;
-  GcomprisAnimation *anim = NULL;
 
   /* read filenames, one per line, from the animation spec-file */
   while(fscanf(f, "%99s", tmp) == 1)
@@ -65,11 +70,6 @@ GcomprisAnimation *gcompris_load_animati
   anim->numstates = g_slist_length(files);
   anim->anim = g_malloc(sizeof(GdkPixbuf*) * anim->numstates);
 
-  /* open the animations and assign them */
-  GError *error = NULL;
-  GSList *cur;
-  char *name;
-  int i;
   for(cur=files, i=0; cur; cur = g_slist_next(cur), i++)
     {
       name = (char*) cur->data;
@@ -169,13 +169,13 @@ void gcompris_set_anim_state(GcomprisAni
 
 static gboolean anim_tick(void *ignore)
 {
+  GSList *cur;
   if(active == NULL)
     {
       printf("deactivating anim_tick\n");
       return FALSE;
     }
 
-  GSList *cur;
   for(cur=active; cur; cur = g_slist_next(cur))
     {
       GcomprisAnimCanvasItem *a = (GcomprisAnimCanvasItem*)cur->data;
