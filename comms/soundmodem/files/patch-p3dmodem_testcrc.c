--- p3dmodem/testcrc.c.orig	2002-08-09 20:01:52 UTC
+++ p3dmodem/testcrc.c
@@ -40,6 +40,8 @@
 
 #define BLOCKSZ  512
 
+unsigned int log_verblevel;
+
 static int testone(void)
 {
 	unsigned char data[BLOCKSZ];
