--- native/jni/native-lib/cpnet.h.orig	2006-09-08 10:59:57.000000000 +0200
+++ native/jni/native-lib/cpnet.h	2008-03-31 18:47:54.000000000 +0200
@@ -41,9 +41,11 @@
 #include <jni.h>
 #include <jcl.h>
 #include <string.h>
 
+#include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in_systm.h>
 #include <netinet/in.h>
 #include <netinet/ip.h>
 
 typedef struct {
