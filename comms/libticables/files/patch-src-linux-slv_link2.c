--- src/linux/slv_link2.c.orig	Sun Sep 26 13:11:20 2004
+++ src/linux/slv_link2.c	Mon May 30 15:27:12 2005
@@ -111,7 +111,7 @@
         {}
 };
 
-//static int max_ps = 32;  // max packet size (32 ot 64)
+static int max_ps = 32;  // max packet size (32 ot 64)
 
 static int nBytesWrite2 = 0;
 static uint8_t *wBuf2 = NULL;
