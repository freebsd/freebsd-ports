--- src/Sample.cc.orig	Sun Oct 29 20:53:54 2006
+++ src/Sample.cc	Sun Oct 29 20:54:32 2006
@@ -12,6 +12,8 @@
 #include <errno.h>
 #ifdef __NetBSD__
 #  include <machine/endian.h>
+#elif __FreeBSD__
+#  include <sys/endian.h>
 #else
 #  include <endian.h>
 #endif
