--- zoofns.h.orig	1993-05-01 03:57:35 UTC
+++ zoofns.h
@@ -94,7 +94,11 @@ void exit PARMS ((int));
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
