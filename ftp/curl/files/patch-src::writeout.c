--- src/writeout.c.orig	Tue May 21 18:27:28 2002
+++ src/writeout.c	Tue May 21 18:27:36 2002
@@ -27,6 +27,7 @@
 #include <string.h>
 
 #ifdef HAVE_SYS_SELECT_H
+#include <sys/types.h>
 #include <sys/select.h>
 #endif
 
