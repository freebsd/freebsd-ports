--- src/linux/rw_sdl.c.orig	Wed Jun 18 08:01:40 2003
+++ src/linux/rw_sdl.c	Wed Jun 18 08:02:13 2003
@@ -190,7 +190,10 @@
 */
 void RW_IN_Commands (void)
 {
-	int i, key_index;
+	int i;
+#ifdef Joystick
+	int key_index;
+#endif
    
 	if (mouse_avail) {
 	  for (i=0 ; i<3 ; i++) {
