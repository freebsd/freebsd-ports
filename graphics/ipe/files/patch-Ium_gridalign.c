
$FreeBSD$

--- Ium/gridalign.c.orig	Fri Nov 29 16:04:46 2002
+++ Ium/gridalign.c	Fri Nov 29 16:04:53 2002
@@ -113,7 +113,7 @@
   ium_output = ium_input;
 }
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   ium_begin(argc, argv);
   
