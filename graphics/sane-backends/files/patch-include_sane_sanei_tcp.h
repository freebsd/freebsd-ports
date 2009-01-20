--- include/sane/sanei_tcp.h.orig	2006-11-30 14:23:19.000000000 -0900
+++ include/sane/sanei_tcp.h	2009-01-16 05:02:42.000000000 -0900
@@ -20,6 +20,7 @@
 
 #include <sane/sane.h>
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netdb.h>
 
