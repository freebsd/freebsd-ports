--- netperf.c.orig	Tue Sep 21 22:33:40 2004
+++ netperf.c	Fri Nov  5 12:58:32 2004
@@ -50,6 +50,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <strings.h>
+#include <sys/types.h>
 
 #ifdef WIN32
 #include <winsock2.h>
