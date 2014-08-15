--- unzip.h.orig	2009-02-15 18:12:54 UTC
+++ unzip.h
@@ -559,6 +559,7 @@ typedef struct _UzpOpts {
 #ifdef UNIX
     int cflxflag;       /* -^: allow control chars in extracted filenames */
 #endif
+    int dotflag;	/* -.: don't translate filenames to local charset */
 #endif /* !FUNZIP */
 } UzpOpts;
 
