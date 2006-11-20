--- src/doodle/index.c.orig	Wed May  3 05:21:21 2006
+++ src/doodle/index.c	Mon Nov 20 11:06:49 2006
@@ -33,6 +33,7 @@
 #include "helper2.h"
 #include "gettext.h"
 #include "doodle.h"
+#include <signal.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <unistd.h>
@@ -327,7 +328,7 @@
     char * cpos;
     size_t slen;
 
-    if (EXTRACTOR_isBinaryType(pos->keywordType)) {
+    if (pos->keywordType == EXTRACTOR_THUMBNAIL_DATA) {
       pos = pos->next;
       continue;
     }
