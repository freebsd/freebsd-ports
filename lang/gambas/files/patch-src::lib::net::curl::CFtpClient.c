--- src/lib/net/curl/CFtpClient.c.orig	Sun Jun 27 14:14:20 2004
+++ src/lib/net/curl/CFtpClient.c	Sun Aug 29 18:34:27 2004
@@ -24,6 +24,11 @@
 #define __CFTPCLIENT_C
 
 #include <stdio.h>
+#if defined(__FreeBSD__)
+/* Don't use the wrappering macro but the real function
+   With gcc-3.4.2 feof(THIS_FILE) is forbidden */
+# undef feof
+#endif
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
