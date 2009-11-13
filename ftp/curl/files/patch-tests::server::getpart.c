Description: Properly allocate a buffer as large as needed.
Forwarded: https://sourceforge.net/tracker/?func=detail&aid=2897159&group_id=976&atid=100976
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2009-11-13

--- a/tests/server/getpart.c
+++ b/tests/server/getpart.c
@@ -87,7 +87,7 @@
     needed_len = len + *stringlen + 1; /* recalculate */
   }
 
-  if(needed_len >= *stralloc) {
+  while(needed_len >= *stralloc) {
     char *newptr;
     size_t newsize = needed_len*2; /* get twice the needed size */
 
