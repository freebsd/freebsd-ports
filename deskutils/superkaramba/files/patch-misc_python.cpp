--- src/misc_python.cpp.orig	Fri Nov 19 13:31:33 2004
+++ src/misc_python.cpp	Fri Nov 19 13:37:12 2004
@@ -380,6 +380,9 @@
 #include <sys/ioctl.h>
 #include <net/if.h>
 #include <arpa/inet.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 
 /* now a method we need to expose to Python */
 QString getIp(char *device_name)
