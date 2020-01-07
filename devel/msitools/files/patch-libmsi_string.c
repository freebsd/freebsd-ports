--- libmsi/string.c.orig	2020-01-07 19:29:38 UTC
+++ libmsi/string.c
@@ -22,7 +22,11 @@
 
 #include <stdarg.h>
 #include <assert.h>
-#include <endian.h>
+#ifdef __FreeBSD__
+#  include <sys/endian.h>
+#else
+#  include <endian.h>
+#endif
 #include <gsf/gsf-msole-utils.h>
 
 #include "debug.h"
