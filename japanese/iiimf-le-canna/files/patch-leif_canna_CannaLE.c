--- leif/canna/CannaLE.c.orig	Wed Oct 13 00:26:27 2004
+++ leif/canna/CannaLE.c	Wed Mar  2 23:37:14 2005
@@ -86,7 +86,7 @@
 
 #include <dlfcn.h>
 #include "csconv.h"
-#define CSC_PATH	"/usr/lib/im/csconv/csconv.so"
+#define CSC_PATH	(IMDIR "/csconv/csconv.so")
 #define CSC_OPEN_LOCALE	"csconv_open_locale"
 #define CSC_OPEN	"csconv_open"
 #define CSC_CONV	"csconv"
@@ -104,11 +104,11 @@
 				       char **, size_t *);
 typedef int		(* csc_close_t)(csconv_t);
 
-static void *			csc_handle;	
-static csc_open_locale_t	csc_open_locale;
-static csc_open_t		csc_open;
-static csc_conv_t		csc_conv;
-static csc_close_t		csc_close;
+static void *			csc_handle = NULL;	
+static csc_open_locale_t	csc_open_locale = NULL;
+static csc_open_t		csc_open = NULL;
+static csc_conv_t		csc_conv = NULL;
+static csc_close_t		csc_close = NULL;
 static csconv_t                 csconv_cd = NULL;
 
 Bool    if_canna_OpenIF();
