
$FreeBSD$

--- util/magnifier.c	2002/04/12 09:58:25	1.1
+++ util/magnifier.c	2002/04/12 10:07:31
@@ -11,7 +11,7 @@
  */
 #define PARENT_TYPE BONOBO_OBJECT_TYPE
 
-struct sockaddr_un mag_server = { AF_UNIX ,  "/tmp/magnifier_socket" };
+struct sockaddr_un mag_server = { 0, AF_UNIX ,  "/tmp/magnifier_socket" };
 
 typedef struct {
 	gchar *target_display;
