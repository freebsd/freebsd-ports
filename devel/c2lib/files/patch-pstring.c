--- pstring.c.orig	Fri Feb 16 18:46:50 2001
+++ pstring.c	Fri Feb 16 18:48:10 2001
@@ -32,6 +32,7 @@
 #endif
 
 #ifdef HAVE_REGEX_H
+#include <sys/types.h>
 #include <regex.h>
 #endif
 
