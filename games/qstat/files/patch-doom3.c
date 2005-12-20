--- doom3.c.orig	Sat Dec 17 14:14:38 2005
+++ doom3.c	Sat Dec 17 14:14:49 2005
@@ -11,6 +11,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #ifndef _WIN32
+#include <sys/types.h>
 #include <sys/socket.h>
 #endif
 
