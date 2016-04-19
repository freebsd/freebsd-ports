--- src/psl.c.orig	2016-01-02 13:38:37 UTC
+++ src/psl.c
@@ -67,6 +67,8 @@
 #endif
 
 #include <sys/types.h>
+#include <netinet/in.h>
+#include <sys/socket.h>
 #include <sys/stat.h>
 #include <unistd.h>
 #include <stdio.h>
