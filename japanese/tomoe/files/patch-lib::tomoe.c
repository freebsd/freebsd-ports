Index: lib/tomoe.c
diff -u -p lib/tomoe.c.orig lib/tomoe.c
--- lib/tomoe.c.orig	Thu Aug 11 11:34:32 2005
+++ lib/tomoe.c	Mon Dec 19 03:31:30 2005
@@ -150,9 +150,9 @@ tomoe_get_matched (glyph *input, candida
   {
     candidate_private *cand;
     int_array *adapted;
+    int pj;
     cand = cands->p[i];
     adapted = cand->adapted_strokes;
-    int pj;
 
     pj = match_stroke_num(cand->index, input->stroke_num, adapted);
 
@@ -471,13 +471,14 @@ load_dictionaries (void)
   stroke *strk = NULL;
   point *pnt = NULL;
   char line_buf[LINE_BUF_SIZE];
+  FILE *fp;
 
   if (g_dict) return;
 
   g_dict = calloc (1, sizeof(dictionary));
   dictionary_alloc_contents (g_dict, DICT_LETTER_INITIAL_SIZE);
 
-  FILE *fp = fopen (TOMOEDATADIR "/all.tdic", "r");
+  fp = fopen (TOMOEDATADIR "/all.tdic", "r");
   while ((p = fgets (line_buf, LINE_BUF_SIZE, fp)) != NULL)
   {
     if (p[0] == '\n')
@@ -766,8 +767,8 @@ get_candidates(stroke *input_stroke, poi
   for (cand_index = 0; cand_index < cands->len; cand_index++)
   {
     tomoe_bool match_flag;
-    match_flag = FALSE;
     int_array *adapted = NULL;
+    match_flag = FALSE;
     cand = cands->p[cand_index];
 
     adapted = int_array_copy (cand->adapted_strokes);
