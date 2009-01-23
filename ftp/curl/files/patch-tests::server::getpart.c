diff -urN -x .svn ../../vendor/curl/tests/server/getpart.c ./tests/server/getpart.c
--- ../../vendor/curl/tests/server/getpart.c	2008-10-23 17:42:39.000000000 +0300
+++ ./tests/server/getpart.c	2009-01-21 16:12:27.000000000 +0200
@@ -87,7 +87,7 @@
     needed_len = len + *stringlen + 1; /* recalculate */
   }
 
-  if(needed_len >= *stralloc) {
+  while(needed_len >= *stralloc) {
     char *newptr;
     size_t newsize = needed_len*2; /* get twice the needed size */
 
