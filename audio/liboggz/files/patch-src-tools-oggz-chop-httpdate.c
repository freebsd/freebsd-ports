--- src/tools/oggz-chop/httpdate.c.orig	2025-02-01 16:51:35 UTC
+++ src/tools/oggz-chop/httpdate.c
@@ -60,7 +60,5 @@ httpdate_parse (char * s, int n)
 
   d.tm_year -= 1900;
 
-  d.tm_sec -= timezone;
-
   return mktime (&d);
 }
