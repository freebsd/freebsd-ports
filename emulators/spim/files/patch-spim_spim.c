--- ./spim/spim.c.orig	Mon Jul 17 09:26:54 2006
+++ ./spim/spim.c	Mon Jul 17 09:27:13 2006
@@ -32,6 +32,7 @@
 #include <ctype.h>
 #include <setjmp.h>
 #include <signal.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 
 
