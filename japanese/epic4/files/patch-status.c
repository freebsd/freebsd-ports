--- source/status.c.orig	Tue Dec  5 09:11:57 2000
+++ source/status.c	Tue Jan  6 01:05:58 2004
@@ -36,7 +36,7 @@
  * Maximum number of "%" expressions in a status line format.  If you change
  * this number, you must manually change the sprintf() in make_status 
  */
-#define STATUS_FUNCTION(x) static Char * ## x (Window *window, int map, int key)
+#define STATUS_FUNCTION(x) static Char * x (Window *window, int map, int key)
 #define MAX_FUNCTIONS 40
 #define MAX_STATUS_USER 39
 
