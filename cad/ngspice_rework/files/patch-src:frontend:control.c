--- src/frontend/control.c.orig	Thu Dec 25 17:30:51 2003
+++ src/frontend/control.c	Fri Sep 24 13:02:13 2004
@@ -822,6 +822,7 @@
 void
 cp_resetcontrol(void)
 {
+    void cp_free_control(void);
     fprintf(cp_err, "Warning: clearing control structures\n");
     if (cend[stackp] && cend[stackp]->co_parent)
         fprintf(cp_err, "Warning: EOF before block terminated\n");
