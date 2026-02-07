--- src/oformat_parser.c.orig	2014-10-02 22:46:20 UTC
+++ src/oformat_parser.c
@@ -336,7 +336,7 @@ char splt_of_get_number_of_digits_from_t
   }
 
   long minutes = total_time / 100 / 60;
-  int i = (int) (log10l((long double) minutes));
+  int i = (int) (log10(minutes));
   char number_of_digits = (char) (i + '1');
   if (number_of_digits == '1')
   {
