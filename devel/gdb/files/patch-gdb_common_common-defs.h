--- gdb/common/common-defs.h.orig	2015-07-06 19:57:46 UTC
+++ gdb/common/common-defs.h
@@ -34,7 +34,9 @@
 #include <stdint.h>
 #include <string.h>
 #include <errno.h>
+#ifndef __FreeBSD__
 #include <alloca.h>
+#endif
 #include "ansidecl.h"
 #include "libiberty.h"
 #include "pathmax.h"
