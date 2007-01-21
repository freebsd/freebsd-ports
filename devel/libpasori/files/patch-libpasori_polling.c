--- src/libpasori_polling.c.orig	Tue May 16 01:45:01 2006
+++ src/libpasori_polling.c	Fri Jan 19 01:09:56 2007
@@ -1,6 +1,8 @@
 /* libpasori polling func. */
 #include <stdlib.h>
+#include <string.h>
 #include "libpasori_liblocal.h"
+#include "libpasori_command.h"
 
 
 felica *
