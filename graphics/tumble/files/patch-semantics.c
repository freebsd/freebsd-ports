--- semantics.c.orig	2021-08-17 12:37:41 UTC
+++ semantics.c
@@ -119,7 +119,7 @@ typedef struct output_page_t
 #endif
 
 
-FILE *yyin;
+extern FILE *yyin;
 int line;  /* line number in spec file */
 
 int bookmark_level;
