--- src/oformat_parser.c.orig	2010-09-07 05:12:05.000000000 +0800
+++ src/oformat_parser.c	2010-09-29 16:12:11.000000000 +0800
@@ -760,7 +760,7 @@
   if (total_time > 0)
   {
     long minutes = total_time / 100 / 60;
-    int i = (int) (log10l((long double) minutes));
+    int i = (int) (log10(minutes));
     char number_of_digits = (char) (i + '1');
     if (number_of_digits == '1')
     {
