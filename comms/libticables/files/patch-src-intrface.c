--- src/intrface.c.orig	Sat Sep 13 18:45:17 2003
+++ src/intrface.c	Sat Sep 13 19:56:41 2003
@@ -722,6 +722,7 @@
 /*********************/
 
 extern const char *search_for_tipar_node(int minor);
+extern const char *search_for_tiser_node(int minor);
 
 static int convert_port_into_device(void)
 {
