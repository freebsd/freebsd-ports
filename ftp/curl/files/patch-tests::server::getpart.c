--- tests/server/getpart.c.orig	Wed Dec 10 15:15:52 2003
+++ tests/server/getpart.c	Wed Dec 10 15:17:19 2003
@@ -21,7 +21,7 @@
   int len = strlen(buffer);
   int needed_len = len + *stringlen;
 
-  if(needed_len >= *stralloc) {
+  while(needed_len >= *stralloc) {
     char *newptr;
     long newsize = needed_len*2; /* get twice the needed size */
 
