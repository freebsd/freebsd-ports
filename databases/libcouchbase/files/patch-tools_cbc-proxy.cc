--- tools/cbc-proxy.cc.orig	2020-06-17 13:30:27 UTC
+++ tools/cbc-proxy.cc
@@ -18,6 +18,7 @@
 
 #include "config.h"
 #include <sys/types.h>
+#include <netinet/in.h>
 #include <libcouchbase/couchbase.h>
 #include <libcouchbase/vbucket.h>
 #include <libcouchbase/api3.h>
