--- util/log_buffer.h.orig	2014-06-20 07:40:32.000000000 +0800
+++ util/log_buffer.h	2014-07-22 22:10:43.912828365 +0800
@@ -5,6 +5,7 @@
 
 #pragma once
 
+#include <sys/time.h>
 #include "rocksdb/env.h"
 #include "util/arena.h"
 #include "util/autovector.h"
