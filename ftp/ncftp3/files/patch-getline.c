--- ncftp/getline.c.orig	Sat Apr  7 16:55:16 2001
+++ ncftp/getline.c	Sun Jul 29 11:10:37 2001
@@ -974,7 +974,12 @@
 	                kill(0, sig);
 	                gl_init();
 	                gl_redraw();
+#if 0
 			return gl_buf;
+#else
+			/* FALLTHROUGH */
+			c = 0; 	/* no beep */
+#endif				
 #endif
 		    }
 #endif /* __unix__ */
