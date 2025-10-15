--- src/test/tester.c.orig	2024-01-31 20:08:46 UTC
+++ src/test/tester.c
@@ -5,7 +5,9 @@
  * Copyright 2012-2018 Peter M. Jones <pjones@redhat.com>
  */
 
-#include <alloca.h>
+#if defined(__linux__)
+#  include <alloca.h>
+#endif
 #include <errno.h>
 #include <fcntl.h>
 #include <stdarg.h>
