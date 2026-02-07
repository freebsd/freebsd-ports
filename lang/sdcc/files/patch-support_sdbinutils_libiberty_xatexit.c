--- support/sdbinutils/libiberty/xatexit.c.orig	2012-02-10 10:16:50 UTC
+++ support/sdbinutils/libiberty/xatexit.c
@@ -25,7 +25,7 @@ failure.  If you use @code{xatexit} to register functi
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
-#include "ansidecl.h"
+#include "../include/ansidecl.h"
 #include "libiberty.h"
 
 #include <stdio.h>
