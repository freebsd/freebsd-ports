--- cliproto.h.orig	Thu Nov 21 20:43:08 2002
+++ cliproto.h	Wed Dec 18 05:27:43 2002
@@ -70,10 +70,7 @@
     cli_oid
 };
 
-#if defined(__FreeBSD__)
-#include <sys/param.h>
-#define USE_HTON_NTOH
-#elif defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 //
 // At Linux inline assembly declarations of ntohl, htonl... are available
 //
