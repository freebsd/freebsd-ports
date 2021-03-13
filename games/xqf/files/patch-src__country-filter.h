--- src/country-filter.h.orig	2014-11-02 00:43:18 UTC
+++ src/country-filter.h
@@ -22,6 +22,9 @@
 
 #include <glib.h>
 #include "pixmaps.h"
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 
 extern unsigned MaxCountries;
