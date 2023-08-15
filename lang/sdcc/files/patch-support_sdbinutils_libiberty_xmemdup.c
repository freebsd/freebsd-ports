--- support/sdbinutils/libiberty/xmemdup.c.orig	2018-03-18 17:46:53 UTC
+++ support/sdbinutils/libiberty/xmemdup.c
@@ -19,7 +19,7 @@ allocated, the remaining memory is zeroed.
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
-#include "ansidecl.h"
+#include "../include/ansidecl.h"
 #include "libiberty.h"
 
 #include <sys/types.h> /* For size_t. */
