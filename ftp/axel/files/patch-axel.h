--- axel.h.orig	Sun Aug  5 23:41:50 2001
+++ axel.h	Sun Aug  5 23:42:26 2001
@@ -30,7 +30,9 @@
 #include <errno.h>
 #include <stdio.h>
 #include <netdb.h>
+#ifndef	NOGETOPTLONG
 #include <getopt.h>
+#endif
 #include <limits.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -41,6 +43,7 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in_systm.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 
