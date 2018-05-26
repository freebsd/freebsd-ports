--- cpp/FacebookBase.h.orig	2018-05-25 20:03:21 UTC
+++ cpp/FacebookBase.h
@@ -22,6 +22,7 @@
 
 #include "FacebookService.h"
 
+#include <boost/shared_ptr.hpp>
 #include <thrift/server/TServer.h>
 #include <thrift/concurrency/Mutex.h>
 
