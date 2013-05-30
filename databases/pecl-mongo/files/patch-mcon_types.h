--- mcon/types.h.orgi	2013-05-31 00:39:17.000000000 +0800
+++ mcon/types.h	2013-05-31 00:40:39.000000000 +0800
@@ -36,6 +36,7 @@
 # define va_copy(d,s) ((void)((d) = (s)))
 #endif
 #else
+# include <sys/types.h>
 # include <stdint.h>
 # include <netinet/in.h>
 # include <netinet/tcp.h>
