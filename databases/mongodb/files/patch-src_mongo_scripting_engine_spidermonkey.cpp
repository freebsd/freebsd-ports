--- src/mongo/scripting/engine_spidermonkey.cpp.orig	2013-03-15 19:59:55.000000000 +0100
+++ src/mongo/scripting/engine_spidermonkey.cpp	2013-03-22 17:54:19.000000000 +0100
@@ -25,7 +25,7 @@
 #include <boost/date_time/posix_time/posix_time.hpp>
 #endif
 
-#include <third_party/js-1.7/jsdate.h>
+#include <jsdate.h>
 
 #include "mongo/scripting/engine_spidermonkey_internal.h"
 #include "mongo/util/mongoutils/str.h"
