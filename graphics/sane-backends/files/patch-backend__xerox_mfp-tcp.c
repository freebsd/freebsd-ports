--- backend/xerox_mfp-tcp.c.orig	2010-12-02 08:49:58.000000000 +0900
+++ backend/xerox_mfp-tcp.c	2011-08-02 02:37:27.000000000 +0900
@@ -27,6 +27,8 @@
 #include <unistd.h>
 #include <errno.h>
 #include <sys/time.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 
 #include "sane/saneopts.h"
 #include "sane/sanei_scsi.h"
