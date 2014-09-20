--- rec_channel.hh.orig	2014-09-09 09:33:33 UTC
+++ rec_channel.hh
@@ -4,6 +4,7 @@
 #include <map>
 #include <inttypes.h>
 #include <sys/un.h>
+#include <pthread.h>
 
 
 /** this class is used both to send and answer channel commands to the PowerDNS Recursor */
