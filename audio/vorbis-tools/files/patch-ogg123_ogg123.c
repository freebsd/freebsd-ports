$FreeBSD$
--- ogg123/ogg123.c.orig	Sat Feb 24 01:52:22 2001
+++ ogg123/ogg123.c	Wed Mar 21 15:30:42 2001
@@ -24,6 +24,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <netdb.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <errno.h>
