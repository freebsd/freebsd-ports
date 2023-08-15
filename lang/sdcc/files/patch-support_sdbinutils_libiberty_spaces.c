--- support/sdbinutils/libiberty/spaces.c.orig	2018-03-18 17:46:53 UTC
+++ support/sdbinutils/libiberty/spaces.c
@@ -32,7 +32,7 @@ valid until at least the next call.
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
-#include "ansidecl.h"
+#include "../include/ansidecl.h"
 #include "libiberty.h"
 
 #if VMS
