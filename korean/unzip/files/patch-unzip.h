--- unzip.h.orig	Sun Jan 27 11:29:40 2002
+++ unzip.h	Wed May 21 03:43:56 2003
@@ -459,6 +459,7 @@
 #if (!defined(RISCOS) && !defined(CMS_MVS) && !defined(TANDEM))
     int ddotflag;       /* -:: don't skip over "../" path elements */
 #endif
+    int dotflag;	/* -.: don't translate filenames to local charset */
 #endif /* !FUNZIP */
 } UzpOpts;
 
