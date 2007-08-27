--- tests/server/getpart.c.orig	Tue Jan 23 13:46:14 2007
+++ tests/server/getpart.c
@@ -76,7 +76,7 @@
     needed_len = len + *stringlen + 1; /* recalculate */
   }
 
-  if(needed_len >= *stralloc) {
+  while(needed_len >= *stralloc) {
     char *newptr;
     size_t newsize = needed_len*2; /* get twice the needed size */
 
