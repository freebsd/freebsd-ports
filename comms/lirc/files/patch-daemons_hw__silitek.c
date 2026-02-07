--- daemons/hw_silitek.c.orig	2011-03-25 22:28:18 UTC
+++ daemons/hw_silitek.c
@@ -41,8 +41,9 @@
 extern struct ir_remote *repeat_remote, *last_remote;
 
 unsigned char b[NUMBYTES];
-ir_code code;
-struct timeval current, last;
+extern ir_code code;
+struct timeval current;
+extern struct timeval last;
 int do_repeat;
 
 struct hardware hw_silitek = {
