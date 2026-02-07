--- daemons/hw_bte.c.orig	2011-03-25 22:28:18 UTC
+++ daemons/hw_bte.c
@@ -56,8 +56,8 @@
 #include "lircd.h"
 #include "hw_bte.h"
 
-struct timeval start, end, last;
-lirc_t gap, signal_length;
+extern struct timeval start, end, last;
+extern lirc_t gap, signal_length;
 ir_code pre, code;
 
 #define BTE_CAN_SEND 0
