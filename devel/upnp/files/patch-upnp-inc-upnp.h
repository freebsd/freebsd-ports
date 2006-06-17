--- upnp/inc/upnp.h.orig	Sat Jun 17 11:57:02 2006
+++ upnp/inc/upnp.h	Sat Jun 17 12:01:43 2006
@@ -37,6 +37,7 @@
 //@{
 
 #include <stdio.h>
+#include <time.h>
 #include "ixml.h"
 #include "upnpconfig.h"
 #if UPNP_HAVE_DEBUG
@@ -48,6 +49,7 @@
 #define UPNP_INVALID_SOCKET     -1
 #define SOCKET                  int
 
+#include <sys/types.h>
 #include <netinet/in.h>
 
 #define LINE_SIZE  180
