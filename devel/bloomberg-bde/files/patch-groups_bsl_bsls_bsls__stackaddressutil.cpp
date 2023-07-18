--- groups/bsl/bsls/bsls_stackaddressutil.cpp.orig	2023-07-31 18:09:19 UTC
+++ groups/bsl/bsls/bsls_stackaddressutil.cpp
@@ -32,6 +32,11 @@ BSLS_IDENT("$Id$ $CSID$")
 # include <sys/ldr.h>
 # include <xcoff.h>
 
+#elif defined(BSLS_PLATFORM_OS_FREEBSD)
+
+#include <execinfo.h>
+#include <stdlib.h>
+
 #elif defined(BSLS_PLATFORM_OS_LINUX)
 
 # include <execinfo.h>
@@ -115,6 +120,10 @@ int getProcessName(char *output, int length)
 
     snprintf(output, length, "%s", pidPathBuf);
     return 0;
+
+#elif defined(BSLS_PLATFORM_OS_FREEBSD)
+    int printed = snprintf(output, length, "%s", getprogname());
+    return (printed >= 0) ? 0 : -1;
 
 #elif defined(BSLS_PLATFORM_OS_LINUX)
 
