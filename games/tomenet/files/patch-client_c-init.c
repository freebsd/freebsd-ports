--- client/c-init.c.orig	2025-05-04 20:53:05 UTC
+++ client/c-init.c
@@ -6,6 +6,7 @@
  * specific system needs its own "main" function (such as
  * Windows), then it should be placed in the "main-???.c" file.
  */
+#include <sys/socket.h>
 
 #ifdef WIN32 /* Note that WINDOWS is not yet defined here, but gets defined in angband.h->config.h->h-config.h below! */
  #include <winsock2.h> /* To slay warning about ws2tcpip.h include */
@@ -3776,7 +3777,8 @@ void client_init(char *argv1, bool skip) {
 #endif
 
 #if defined(USE_X11) || defined(USE_GCU)
- #ifndef OSX
+// #ifndef OSX
+ #if !defined(OSX) && !defined(__FreeBSD__)
 		#include <sys/ioctl.h>
 		#include <net/if.h>
 		struct ifreq ifr;
