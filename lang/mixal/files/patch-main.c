--- main.c.orig	Mon Jun  3 17:53:11 2002
+++ main.c	Mon Jun  3 17:53:23 2002
@@ -104,6 +104,7 @@
 
 int main(int argc, char **argv)
 {
+    initialize_io();
     precompute_field_data();
 
     /* Assemble the input: */
