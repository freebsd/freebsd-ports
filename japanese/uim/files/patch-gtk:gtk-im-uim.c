--- gtk/gtk-im-uim.c.orig	Sun Aug 31 15:40:29 2003
+++ gtk/gtk-im-uim.c	Sun Aug 31 15:41:10 2003
@@ -109,10 +109,12 @@
 static void
 pushback_cb(void *ptr, int attr, char *str)
 {
+  IMUIMContext *uic;
+
   if(!str)
     return;
 
-  IMUIMContext *uic = ptr;
+  uic = ptr;
   uic->pseg = realloc(uic->pseg,
 		      sizeof(struct preedit_segment) *
 		     (uic->nr_psegs + 1));
