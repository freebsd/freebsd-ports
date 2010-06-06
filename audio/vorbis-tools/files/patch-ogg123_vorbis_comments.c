$FreeBSD$
--- ogg123/vorbis_comments.c.orig	2010-06-05 16:48:23.000000000 +0200
+++ ogg123/vorbis_comments.c	2010-06-05 16:55:21.000000000 +0200
@@ -72,7 +72,7 @@ char *lookup_comment_prettyprint (char *
 
   /* Use default formatting */
   j = strcspn(comment, "=");
-  if (j) {
+  if (j != strlen(comment)) {
     *offset = j + 1;
     s = malloc(j + 2);
     if (s == NULL) {
