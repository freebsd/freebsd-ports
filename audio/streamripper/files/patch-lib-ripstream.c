--- lib/ripstream.c.orig	Sat Aug  4 20:08:50 2001
+++ lib/ripstream.c	Mon Jan  7 15:06:25 2002
@@ -22,6 +22,7 @@
 #include <string.h>
 #ifndef _WIN32
 
+#include <sys/types.h>
 #include <netinet/in.h>
 
 #endif
