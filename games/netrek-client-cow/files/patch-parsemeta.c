--- ./parsemeta.c.orig	2011-10-18 05:35:34.000000000 -0500
+++ ./parsemeta.c	2012-04-23 18:10:20.000000000 -0500
@@ -20,6 +20,7 @@
 #include <arpa/inet.h>
 #include <netdb.h>
 #include <errno.h>
+#include <signal.h>
 
 #include "Wlib.h"
 #include "defs.h"
