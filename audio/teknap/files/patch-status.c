--- source/status.c.orig	Sun Jul 20 14:33:43 2003
+++ source/status.c	Sun Jul 20 15:01:05 2003
@@ -38,7 +38,7 @@
  * Maximum number of "%" expressions in a status line format.  If you change
  * this number, you must manually change the sprintf() in make_status 
  */
-#define STATUS_FUNCTION(x) static Char * ## x (Window *window, int map, int key)
+#define STATUS_FUNCTION(x) static Char * x (Window *window, int map, int key)
 #define MAX_FUNCTIONS 40
 #define MAX_STATUS_USER 19
 
