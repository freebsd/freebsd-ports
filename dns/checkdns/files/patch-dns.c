--- ./dns.c.orig	2011-07-01 03:28:55.000000000 +0200
+++ ./dns.c	2011-07-01 03:29:06.000000000 +0200
@@ -11,6 +11,7 @@
 #include <arpa/inet.h>
 #include <arpa/nameser.h>
 #include <resolv.h>
+#include <string.h>
 
 #include "defs.h"
 #include "tools.h"
