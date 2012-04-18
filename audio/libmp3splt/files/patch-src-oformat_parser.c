--- src/oformat_parser.c.orig	2011-11-11 22:14:03.000000000 +0100
+++ src/oformat_parser.c	2012-04-11 09:45:52.000000000 +0200
@@ -301,7 +301,7 @@
   }
 
   long minutes = total_time / 100 / 60;
-  int i = (int) (log10l((long double) minutes));
+  int i = (int) (log10(minutes));
   char number_of_digits = (char) (i + '1');
   if (number_of_digits == '1')
   {
