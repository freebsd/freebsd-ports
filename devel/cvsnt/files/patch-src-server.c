--- src/server.c.orig	Sat Feb 28 00:34:19 2004
+++ src/server.c	Sat Feb 28 00:34:26 2004
@@ -75,7 +75,6 @@
 #   endif
 
 #ifdef HAVE_PAM
-#include <security/pam_misc.h>
 #include <security/pam_appl.h>
 #endif
 
