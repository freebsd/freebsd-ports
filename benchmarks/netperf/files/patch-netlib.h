--- netlib.h.orig	Tue Sep 21 22:33:40 2004
+++ netlib.h	Fri Nov  5 12:56:59 2004
@@ -275,6 +275,11 @@
 	      (errno == WSAECONNRESET) ))
 #endif
 
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+#define	HAVE_BCOPY
+#define	HAVE_BZERO
+#endif	/* __FreeBSD__ || __NetBSD__ */
+
 #ifdef HAVE_SENDFILE
 
 struct sendfile_ring_elt {
@@ -411,6 +416,7 @@
 extern  int     dl_open(char devfile[], int ppa);
 extern  char    format_cpu_method(int method);
 extern unsigned int convert(char *string);
+extern  int     delta_micro();
 
  /* these are all for the confidence interval stuff */
 extern double confidence;
