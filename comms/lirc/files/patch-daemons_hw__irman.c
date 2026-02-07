--- daemons/hw_irman.c.orig	2011-03-25 22:28:18 UTC
+++ daemons/hw_irman.c
@@ -40,9 +40,9 @@
 extern struct ir_remote *repeat_remote, *last_remote;
 
 unsigned char *codestring;
-struct timeval start, end, last;
-lirc_t gap;
-ir_code code;
+extern struct timeval start, end, last;
+extern lirc_t gap;
+extern ir_code code;
 
 #define CODE_LENGTH 64
 
