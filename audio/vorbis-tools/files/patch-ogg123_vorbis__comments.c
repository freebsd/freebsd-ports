--- ogg123/vorbis_comments.c.orig	2010-01-27 04:14:11 UTC
+++ ogg123/vorbis_comments.c
@@ -72,7 +72,7 @@ char *lookup_comment_prettyprint (char *
 
   /* Use default formatting */
   j = strcspn(comment, "=");
-  if (j) {
+  if (j != strlen(comment)) {
     *offset = j + 1;
     s = malloc(j + 2);
     if (s == NULL) {
