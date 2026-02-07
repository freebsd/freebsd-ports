--- src/tools/oggz-chop/httpdate_test.c.orig	2025-02-01 16:51:35 UTC
+++ src/tools/oggz-chop/httpdate_test.c
@@ -21,7 +21,6 @@ main (int UNUSED(argc), char * UNUSED(argv[]))
   if (t == (time_t)-1) {
     FAIL ("Parse error");
   } else {
-    t -= timezone;
     httpdate_snprint (d_out, 30, t);
 
     INFO ("Output date:");
