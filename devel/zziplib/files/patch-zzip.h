--- zzip.h.orig	Sun Jul 28 16:42:36 2002
+++ zzip.h	Sun Jul 28 16:43:15 2002
@@ -19,7 +19,9 @@
 #define _ZZIP_H
 
 #include <zzip-conf.h>
+#ifndef  __FreeBSD__
 #include <zzip-stdint.h>
+#endif
 #include <zziplib.h>
 #include <zzip-io.h>
 
