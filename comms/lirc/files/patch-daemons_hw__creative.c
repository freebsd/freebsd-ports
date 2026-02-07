--- daemons/hw_creative.c.orig	2011-03-25 22:28:18 UTC
+++ daemons/hw_creative.c
@@ -39,10 +39,11 @@
 
 extern struct ir_remote *repeat_remote, *last_remote;
 
-unsigned char b[NUMBYTES];
+extern unsigned char b[NUMBYTES];
 struct timeval start, end, last;
-lirc_t gap, signal_length;
-ir_code pre, code;
+extern lirc_t gap;
+lirc_t signal_length;
+extern ir_code pre, code;
 
 struct hardware hw_creative = {
 	LIRC_IRTTY,		/* default device */
