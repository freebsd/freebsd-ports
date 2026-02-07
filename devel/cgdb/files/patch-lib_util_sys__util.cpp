--- lib/util/sys_util.cpp.orig	2017-12-31 01:38:05 UTC
+++ lib/util/sys_util.cpp
@@ -2,6 +2,8 @@
 #include "config.h"
 #endif /* HAVE_CONFIG_H */
 
+#define _GNU_SOURCE 1
+
 #if HAVE_STDIO_H
 #include <stdio.h>
 #endif /* HAVE_STDIO_H */
