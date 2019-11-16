--- backend/epsonds.c.orig	2019-10-09 14:38:54 UTC
+++ backend/epsonds.c
@@ -48,6 +48,8 @@
 # include <sys/time.h>
 #endif
 #include <unistd.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 
 #include "sane/saneopts.h"
 #include "sane/sanei_config.h"
