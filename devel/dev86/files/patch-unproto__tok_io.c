--- unproto/tok_io.c.orig	2012-07-22 15:06:47.000000000 +0200
+++ unproto/tok_io.c	2012-07-22 15:08:08.000000000 +0200
@@ -189,7 +189,7 @@
 
 /* do_control - parse control line */
 
-static int do_control()
+static void do_control()
 {
     struct token *t;
     int     line;
