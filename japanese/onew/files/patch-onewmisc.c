--- onewmisc.c.orig	1994-02-25 16:57:18.000000000 +0900
+++ onewmisc.c	2014-05-25 11:49:34.000000000 +0900
@@ -99,6 +99,7 @@
 	message = func;
 }
 
+#if 0
 static FILE *LOG;
 Onew_dbglog(fmt,a,b,c,d,e,f,g)
 	char *fmt;
@@ -116,7 +117,7 @@
 	fprintf(LOG,fmt,a,b,c,d,e,f,g);
 	fflush(LOG);
 }
-
+#endif
 
 Onew_non_ascii(str)
 	char *str;
@@ -147,6 +148,7 @@
 	}
 	return 0;
 }
+void
 strQenq(Q,c)
 	Uchar *Q,c;
 {	int len;
@@ -157,6 +159,7 @@
 	Q[len] = c;
 	Q[len+1] = 0;
 }
+void
 strQins(Q,c)
 	Uchar *Q,c;
 {	Linebuff buff;
