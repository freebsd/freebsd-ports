--- ../cl/cl.h.orig	2001-07-08 09:06:11.000000000 -0400
+++ ../cl/cl.h	2007-11-15 14:19:16.000000000 -0500
@@ -80,6 +80,7 @@
 #define	CLP(sp)		((CL_PRIVATE *)((sp)->gp->cl_private))
 #define	GCLP(gp)	((CL_PRIVATE *)gp->cl_private)
 #define	CLSP(sp)	((WINDOW *)((sp)->cl_private))
+#define	LCLSP(sp)	((sp)->cl_private)
 
 /* Return possibilities from the keyboard read routine. */
 typedef enum { INP_OK=0, INP_EOF, INP_ERR, INP_INTR, INP_TIMEOUT } input_t;
