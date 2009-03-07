Properly allocate a buffer as large as needed.

--- a/tests/server/getpart.c
+++ b/tests/server/getpart.c
@@ -87,7 +87,7 @@
     needed_len = len + *stringlen + 1; /* recalculate */
   }
 
-  if(needed_len >= *stralloc) {
+  while(needed_len >= *stralloc) {
     char *newptr;
     size_t newsize = needed_len*2; /* get twice the needed size */
 
