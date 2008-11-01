--- checkout.c	8 Jul 2008 12:29:58 -0000	1.156
+++ checkout.c	17 Oct 2008 08:51:45 -0000
@@ -352,6 +352,7 @@
 				xfree(module_repo_root);
 		}
 
+#define TAILQ_END(head)                 NULL
 		if (mc->mc_canfree == 1) {
 			for (fl = TAILQ_FIRST(&(mc->mc_modules));
 			    fl != TAILQ_END(&(mc->mc_modules)); fl = nxt) {

