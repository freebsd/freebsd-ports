--- xmisc.c.orig	Wed Apr 18 13:23:16 2001
+++ src/xmisc.c	Wed Apr 18 13:23:22 2001
@@ -298,7 +298,7 @@
   if (cb_buffer) free(cb_buffer);
   l = len < 0 ? strlen(text) : len;
   cb_buffer = smalloc(l+1);
-  strncpy(cb_buffer, text, l);
+  strncpy((char *)cb_buffer, text, l);
   cb_buffer[l] = 0;
 
   XSetSelectionOwner(display, XA_PRIMARY, win, CurrentTime);
