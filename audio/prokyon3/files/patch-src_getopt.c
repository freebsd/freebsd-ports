--- src/getopt.c.orig	Sat Sep 20 10:34:30 2003
+++ src/getopt.c	Sat Sep 20 10:35:56 2003
@@ -24,6 +24,8 @@
 #include "config.h"
 #endif
 
+#define _(String)(String)
+
 #ifndef __STDC__
 /* This is a separate conditional since some stdc systems
    reject `defined (const)'.  */
