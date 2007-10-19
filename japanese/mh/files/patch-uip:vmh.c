--- uip/vmh.c.orig	2001-04-21 20:16:49 +0900
+++ uip/vmh.c	2007-10-19 12:51:52 +0900
@@ -116,6 +116,13 @@
 
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
