--- netlib.h	21 Jan 2003 00:26:13 -0000	1.1.1.3
+++ netlib.h	21 Jan 2003 00:45:02 -0000
@@ -305,6 +305,7 @@
 extern  int     dl_open();
 extern  char    format_cpu_method();
 extern unsigned int convert();
+extern  int     delta_micro();
 
  /* these are all for the confidence interval stuff */
 extern double confidence;
@@ -317,6 +318,11 @@
 #define HAVE_BCOPY
 #define HAVE_BZERO
 #endif
+
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+#define	HAVE_BCOPY
+#define	HAVE_BZERO
+#endif	/* __FreeBSD__ || __NetBSD__ */
 
 #ifndef HAVE_BCOPY
 #define bcopy(s,d,h) memcpy((d),(s),(h))
