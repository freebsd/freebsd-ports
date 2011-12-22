--- ./zoofns.h.orig	1993-05-01 05:57:35.000000000 +0200
+++ ./zoofns.h	2011-12-22 14:00:55.000000000 +0100
@@ -94,7 +94,11 @@
 void fixslash PARMS ((char *));
 void makelist PARMS ((int, char *[], char *[], int, char *, char *, char *, int *));
 void memerr PARMS ((unsigned int));
+#ifdef STDARG
+void prterror(int level, char *format, ...);
+#else
 void prterror PARMS ((int, char *, ...));
+#endif
 void rootname PARMS ((char *, char *));
 void skip_files PARMS ((ZOOFILE, unsigned int *, unsigned int *, int *,
                   char [], long *));
