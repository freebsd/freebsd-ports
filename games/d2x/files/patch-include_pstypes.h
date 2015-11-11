--- include/pstypes.h.orig	2003-04-11 23:51:48 UTC
+++ include/pstypes.h
@@ -46,7 +46,7 @@ typedef uint16_t u_int16_t;
 # include <sys/types.h>
 # define _MAX_PATH 1024
 # define _MAX_DIR 256
-# if defined(__APPLE__) && defined(__MACH__)
+# if ( defined(__APPLE__) && defined(__MACH__)) || defined (__FreeBSD__)
 typedef unsigned long ulong;
 # endif
 # ifdef __sun__
