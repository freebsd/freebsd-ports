--- vm/builtin/system.cpp.orig	2010-10-11 00:24:08.000000000 -0700
+++ vm/builtin/system.cpp	2010-10-11 00:24:59.000000000 -0700
@@ -11,6 +11,10 @@
 #include <unistd.h>
 #include <pwd.h>
 
+#include <sys/types.h>
+#include <sys/time.h>
+#include <sys/resource.h>
+
 #include "vm/call_frame.hpp"
 #include "vm/helpers.hpp"
 
