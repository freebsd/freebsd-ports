--- content/common/common_sandbox_support_linux.cc.orig	2021-01-07 00:36:33 UTC
+++ content/common/common_sandbox_support_linux.cc
@@ -5,6 +5,7 @@
 #include "content/public/common/common_sandbox_support_linux.h"
 
 #include <sys/stat.h>
+#include <unistd.h>
 
 #include <limits>
 #include <memory>
