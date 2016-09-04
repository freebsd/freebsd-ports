--- lib/nsrep.h.orig	2016-08-24 12:05:47 UTC
+++ lib/nsrep.h
@@ -19,6 +19,7 @@
 #include <netinet/in.h>
 #include <libknot/dname.h>
 #include <limits.h>
+#include <sys/socket.h>
 
 #include "lib/defines.h"
 #include "lib/generic/map.h"
