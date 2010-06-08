--- checkout.c.orig	2009-06-21 22:23:01.000000000 +0200
+++ checkout.c	2010-06-08 20:18:08.000000000 +0200
@@ -364,6 +364,7 @@
 				xfree(module_repo_root);
 		}
 
+#define TAILQ_END(head)                 NULL
 		if (mc->mc_canfree == 1) {
 			for (fl = RB_MIN(cvs_flisthead, &(mc->mc_modules));
 			    fl != NULL; fl = nxt) {
