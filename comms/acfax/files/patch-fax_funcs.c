--- fax_funcs.c.orig	1998-10-11 16:34:37 UTC
+++ fax_funcs.c
@@ -37,6 +37,8 @@
 #include "widgets.h"
 #include "fax_funcs.h"
 
+#define PI M_PI
+
 /* some variables that are allowed to be global */
 int	lpm;		/* lines per minute */
 int     ixoc;           /* number of pixels of one scan-line / PI */
@@ -96,7 +98,7 @@ char	*mod_end;	/* pointer to first byte behind end of 
 FILE	*fsfile;	/* file pointer of current save-file */
 char	faxsavename[256]; /* current name of save-file */
 char	*saveline;	/* storage for 1 image-line in save_func */
-XtAppContext	mainapp; /* main app.context (needed for interv.timer) */
+extern XtAppContext	mainapp; /* main app.context (needed for interv.timer) */
 XtIntervalId	chstime; /* for the repetitive called background function */
 XtInputId	dspxid = 0; /* for the background function when using select() */
 XEvent	event;		/* event needed to form the XtAppMainLoop */
@@ -117,7 +119,7 @@ void init_fax(void)
   if (fax_inited) return;
   fprintf(stderr, "initializing FAX procedures and alloc'ing core-space\n");
   lpm = 120;
-  ixoc = 288;
+  ixoc = 576;
   devi = 400;
   mod_mode = MOD_FM | FIL_MIDL;
   dmaxval = 63;
