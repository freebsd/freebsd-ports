--- ../unzip/source/file_io.c.orig	Mon Apr 15 16:59:43 2002
+++ ../unzip/source/file_io.c	Mon Apr 15 17:05:38 2002
@@ -865,7 +865,9 @@
 	static struct timeb tbp;
 #endif /* !__386BSD__ */
 #else /* !BSD */
+#if (!defined(FREEBSD) && !defined(NETSBD))
 	extern long timezone;
+#endif
 #endif /* ?BSD */
 #endif /* ?AMIGA */
 
