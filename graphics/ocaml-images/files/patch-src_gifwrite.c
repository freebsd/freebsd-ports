--- ./src/gifwrite.c.orig	2010-04-09 03:01:01.000000000 -0700
+++ ./src/gifwrite.c	2010-04-09 03:01:08.000000000 -0700
@@ -25,7 +25,7 @@
 
 #include <gif_lib.h>
 
-int list_length( value list )
+static int list_length( value list )
 {
   CAMLparam1(list);
   CAMLlocal1(l);
