--- src/util/u_endian.h.orig	2016-11-10 22:05:17 UTC
+++ src/util/u_endian.h
@@ -54,7 +54,7 @@
 # define PIPE_ARCH_BIG_ENDIAN
 #endif
 
-#elif defined(__OpenBSD__) || defined(__NetBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/types.h>
 #include <machine/endian.h>
 
