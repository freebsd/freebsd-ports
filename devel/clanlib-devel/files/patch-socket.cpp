--- Sources/Network/Socket/socket.cpp.orig	Thu Sep 11 18:42:36 2003
+++ Sources/Network/Socket/socket.cpp	Sat Sep 20 12:15:04 2003
@@ -25,6 +25,8 @@
 #else
 #include <unistd.h>
 #include <fcntl.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/tcp.h>
 #include <net/if.h>    // needed for struct ifreq and struct ifconf
 #include <sys/ioctl.h> // needed for ioctl ( on linux and bsd )
