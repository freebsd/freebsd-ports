--- compat.h.orig	Sat Sep 13 16:53:04 2003
+++ compat.h	Tue Oct 28 12:48:07 2003
@@ -45,7 +45,7 @@
 
 /* Replacement functions */
 #ifndef HAVE_GETOPT_LONG
-#include "compat/getopt.h"
+#include "getopt.h"
 #endif				/* #ifndef HAVE_GETOPT_LONG */
 
 #ifndef HAVE_MKSTEMP
