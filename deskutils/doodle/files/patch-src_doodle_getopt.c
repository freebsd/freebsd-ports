--- src/doodle/getopt.c.orig	Sun Jun 26 15:11:31 2005
+++ src/doodle/getopt.c	Sun Jun 26 15:12:05 2005
@@ -84,6 +84,7 @@
 #endif
 
 #include "gettext.h"
+#include "helper1.h"
 
 /* This version of `getopt' appears to the caller like standard Unix `getopt'
    but it behaves differently for the user, since it allows the user
