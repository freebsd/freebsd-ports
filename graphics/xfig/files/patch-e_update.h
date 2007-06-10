--- e_update.h.orig	Tue Jul 26 10:29:34 2005
+++ e_update.h
@@ -14,6 +14,6 @@
  *
  */
 
-extern int update_text(F_text *text);
+extern void update_text(F_text *text);
 extern void fix_fillstyle (void *object);
 extern void update_selected (void);
