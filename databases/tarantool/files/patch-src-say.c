--- src/say.c.orig	2018-10-12 19:53:35 UTC
+++ src/say.c
@@ -37,6 +37,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netdb.h>
+#include <netinet/in.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include <fcntl.h>
