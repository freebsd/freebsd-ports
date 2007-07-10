--- ext/bigdecimal/bigdecimal.c.orig	Tue Feb 27 14:51:55 2007
+++ ext/bigdecimal/bigdecimal.c	Fri Mar 16 13:07:26 2007
@@ -3921,7 +3921,7 @@
     /* get integer part */
     i = 0;
     sign = 1;
-    if(ni > 0) {
+    if(ni >= 0) {
         if(int_chr[0] == '-') {
             sign = -1;
             ++i;
