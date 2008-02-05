--- dice.c.orig	2008-01-11 07:30:32.000000000 +0100
+++ dice.c	2008-01-11 07:31:35.000000000 +0100
@@ -34,6 +34,7 @@
 #include <unistd.h>
 #endif
 #include <stdlib.h>
+#include <string.h>
 
 #if HAVE_SOCKETS
 #ifndef WIN32
