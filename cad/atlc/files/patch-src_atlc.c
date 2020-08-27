--- src/atlc.c.orig	2020-08-27 19:12:32 UTC
+++ src/atlc.c
@@ -68,7 +68,7 @@ struct pixels Er_in_bitmap[MAX_DIFFERENT_PERMITTIVITIE
 
 double **Vij;
 double **Er;
-unsigned char **oddity; 
+extern unsigned char **oddity; 
 unsigned char **cell_type; 
 unsigned char *image_data;
 int width=-1, height=-1;
