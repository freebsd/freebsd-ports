--- include/utils.h.orig	2020-10-29 02:42:44 UTC
+++ include/utils.h
@@ -31,6 +31,8 @@
 #include <stdio.h>
 #include <stdint.h>
 
+#include <netinet/in.h>
+
 #include "compat.h"
 
 #define MDNS_DN_MAXSZ 256 // domain name maximum size
