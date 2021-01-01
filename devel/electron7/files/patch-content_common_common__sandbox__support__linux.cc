--- content/common/common_sandbox_support_linux.cc.orig	2019-12-12 12:39:40 UTC
+++ content/common/common_sandbox_support_linux.cc
@@ -5,6 +5,7 @@
 #include "content/public/common/common_sandbox_support_linux.h"
 
 #include <sys/stat.h>
+#include <unistd.h>
 
 #include <limits>
 #include <memory>
