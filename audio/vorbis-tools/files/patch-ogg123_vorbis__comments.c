--- ogg123/vorbis_comments.c.orig	2021-01-07 23:31:25 UTC
+++ ogg123/vorbis_comments.c
@@ -74,7 +74,7 @@ char *lookup_comment_prettyprint (const char *comment,
 
   /* Use default formatting */
   j = strcspn(comment, "=");
-  if (j) {
+  if (j != strlen(comment)) {
     *offset = j + 1;
     s = malloc(j + 2);
     if (s == NULL) {
