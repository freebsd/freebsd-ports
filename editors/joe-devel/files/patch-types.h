--- types.h.orig	Sun Dec 23 19:26:52 2001
+++ types.h	Sun Dec 23 19:27:07 2001
@@ -163,6 +163,7 @@
 	int	rdonly;		/* Set for read-only */
 	int	internal;	/* Set for internal buffers */
 	int	er;		/* Error code when file was loaded */
+	int	filehandle;	/* File handle for locking */
 };
 
 
