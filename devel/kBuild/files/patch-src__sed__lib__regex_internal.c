--- src/sed/lib/regex_internal.c.orig	2012-07-17 18:30:18.000000000 -0400
+++ src/sed/lib/regex_internal.c	2014-03-13 12:52:57.000000000 -0400
@@ -781,7 +781,7 @@
 }
 
 static unsigned char
-internal_function __attribute ((pure))
+internal_function
 re_string_fetch_byte_case (re_string_t *pstr)
 {
   if (BE (!pstr->mbs_allocated, 1))
