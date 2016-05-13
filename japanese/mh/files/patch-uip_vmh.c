--- uip/vmh.c.orig	2001-04-21 11:16:49 UTC
+++ uip/vmh.c
@@ -116,6 +116,13 @@ void     __cputchar __P((int));
 
 #define	XYZ			/* XXX */
 
+#if defined(__FreeBSD__) && __FreeBSD__ >= 5
+struct ldat
+{
+	unsigned long	*text;
+};
+#endif
+
 /*  */
 
 static struct swit switches[] = {
