--- polyp/module-protocol-stub.c.orig	Fri Dec 31 15:22:48 2004
+++ polyp/module-protocol-stub.c	Fri Dec 31 15:34:51 2004
@@ -28,6 +28,7 @@
 #include <stdio.h>
 #include <assert.h>
 #include <arpa/inet.h>
+#include <sys/syslimits.h>
 #include <unistd.h>
 #include <netinet/in.h>
 
