--- backend/epsonds.c.orig	2017-05-15 01:19:11 UTC
+++ backend/epsonds.c
@@ -40,6 +40,8 @@
 
 #include "sane/config.h"
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <ctype.h>
 #include <unistd.h>
 
