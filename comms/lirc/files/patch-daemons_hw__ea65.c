--- daemons/hw_ea65.c.orig	2011-03-25 22:28:18 UTC
+++ daemons/hw_ea65.c
@@ -50,8 +50,8 @@
 #define TIMEOUT     60000
 #define CODE_LENGTH 24
 
-struct timeval start, end, last;
-ir_code code;
+extern struct timeval start, end, last;
+extern ir_code code;
 
 struct hardware hw_ea65 = {
 	LIRC_IRTTY,		/* default device */
