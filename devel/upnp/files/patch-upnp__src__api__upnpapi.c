--- ./upnp/src/api/upnpapi.c.orig	2009-04-20 09:15:43.000000000 -0300
+++ ./upnp/src/api/upnpapi.c	2009-04-20 09:15:55.000000000 -0300
@@ -44,11 +44,11 @@
 
 #ifndef WIN32
 	#include <arpa/inet.h>
+	#include <sys/socket.h>
 	#include <net/if.h>
 	#include <netinet/in.h>
 	#include <sys/ioctl.h>
 	#include <sys/param.h>
-	#include <sys/socket.h>
 	#include <sys/types.h>
 	#include <sys/utsname.h>
 
