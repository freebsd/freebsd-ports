--- src/country-filter.h.orig	Sun Oct  5 21:53:51 2003
+++ src/country-filter.h	Fri Nov 28 11:11:26 2003
@@ -22,6 +22,9 @@
 
 #include <glib.h>
 #include "pixmaps.h"
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 
 extern const unsigned MaxCountries;
