--- cmdline.h.orig	Fri Jun  8 10:59:27 2001
+++ cmdline.h	Wed Jun 13 19:53:13 2001
@@ -24,7 +24,6 @@
   int shuffle_flag;	/* Show images in random order (default=off).  */
   int load_requested_flag;	/* Load only when requested (default=off).  */
   int verbose_flag;	/* Verbose mode (default=off).  */
-  int recursive_flag;	/* Process directories recursively (default=off).  */
   int info_flag;	/* Show infos about displayed image (default=off).  */
   int maximize_flag;	/* Maximize image to fit screen (default=off).  */
   int delay_arg;	/* Delay before hiding the cursor.  */
@@ -35,7 +34,6 @@
   int shuffle_given ;	/* Whether shuffle was given.  */
   int load_requested_given ;	/* Whether load-requested was given.  */
   int verbose_given ;	/* Whether verbose was given.  */
-  int recursive_given ;	/* Whether recursive was given.  */
   int info_given ;	/* Whether info was given.  */
   int maximize_given ;	/* Whether maximize was given.  */
   int delay_given ;	/* Whether delay was given.  */
