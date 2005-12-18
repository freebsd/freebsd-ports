Index: src/match.c
diff -u -p src/match.c.orig src/match.c
--- src/match.c.orig	Mon Dec 27 13:36:00 2004
+++ src/match.c	Mon Dec 19 03:33:58 2005
@@ -547,10 +547,11 @@ load_data ()
   letter *lttr = NULL;
   stroke *strk = NULL;
   point *pnt = NULL;
+  FILE *fp;
 
   dictionary_alloc_contents(&dict, DICT_LETTER_INITIAL_SIZE);
 
-  FILE *fp = fopen(TOMOEDATADIR "/all.tdic", "r");
+  fp = fopen(TOMOEDATADIR "/all.tdic", "r");
   while ((p = fgets(line_buf, LINE_BUF_SIZE, fp)) != NULL)
     {
       if (p[0] == '\n')
