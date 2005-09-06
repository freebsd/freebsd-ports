--- src/doodle/index.c.orig	Tue Sep  6 16:15:31 2005
+++ src/doodle/index.c	Tue Sep  6 16:15:53 2005
@@ -54,7 +54,7 @@
     char * cpos;
     size_t slen;
 
-    if (EXTRACTOR_isBinaryType(pos->keywordType)) {
+    if (pos->keywordType == EXTRACTOR_THUMBNAIL_DATA) {
       pos = pos->next;
       continue;
     }
