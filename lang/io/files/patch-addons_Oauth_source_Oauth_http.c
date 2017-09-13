--- addons/Oauth/source/Oauth/http.c.orig	2017-09-13 10:44:59 UTC
+++ addons/Oauth/source/Oauth/http.c
@@ -6,7 +6,10 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <sys/select.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <fcntl.h>
 #include <errno.h>
