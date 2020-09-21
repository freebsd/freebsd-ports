--- daemons/hw_livedrive_common.c.orig	2011-03-25 22:28:18 UTC
+++ daemons/hw_livedrive_common.c
@@ -38,8 +38,8 @@
 #include "lircd.h"
 #include "hw_livedrive_common.h"
 
-struct timeval start, end, last;
-ir_code pre, code;
+extern struct timeval start, end, last;
+extern ir_code pre, code;
 
 int livedrive_init(void)
 {
