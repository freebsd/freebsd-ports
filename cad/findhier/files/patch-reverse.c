--- reverse.c.orig	Sun Apr 29 00:54:40 2007
+++ reverse.c	Sun Apr 29 00:54:49 2007
@@ -85,7 +85,7 @@
 		warning("Cell |%s| not found.\n",mytop);
 		exit(-1);
 	}
-#endif __OLD__
+#endif /* __OLD__ */
 	warning("Cell |%s| not found.\n",mytop);
 	return((struct branch *)NULL);
 }
