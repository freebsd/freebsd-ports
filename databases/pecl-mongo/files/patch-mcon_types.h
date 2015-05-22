--- mcon/types.h.orig	2015-05-11 20:59:21 UTC
+++ mcon/types.h
@@ -36,6 +36,7 @@ typedef unsigned __int64 uint64_t;
 # define va_copy(d,s) ((void)((d) = (s)))
 #endif
 #else
+# include <sys/types.h>
 # include <stdint.h>
 # include <sys/types.h>
 # include <netinet/in.h>
