--- backend/epson2.c.orig	2010-04-05 22:18:04.000000000 +0900
+++ backend/epson2.c	2010-05-10 22:18:47.000000000 +0900
@@ -57,6 +57,8 @@
 #include <unistd.h>
 #include <errno.h>
 #include <sys/time.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 
 #include "sane/saneopts.h"
 #include "sane/sanei_scsi.h"
