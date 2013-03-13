--- agent/lib/port.c.orig	2013-03-09 18:29:25.828440497 +0900
+++ agent/lib/port.c	2013-03-09 18:30:03.711650531 +0900
@@ -8,7 +8,11 @@
 
 #ifndef WIN32
 
+#if defined(__FreeBSD__)
+#include <sys/mount.h>
+#else
 #include <sys/statfs.h>
+#endif
 #include <unistd.h>
 
 bool
