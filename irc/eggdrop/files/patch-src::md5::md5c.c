--- eggdrop1.6.17/src/md5/md5c.c.orig	Fri Sep  3 14:08:28 2004
+++ eggdrop1.6.17/src/md5/md5c.c	Fri Sep  3 14:04:51 2004
@@ -25,6 +25,7 @@
 
 #include "compat/compat.h"
 
+#ifdef EGG_SSL_EXT
 typedef unsigned long MD5_u32plus;
 
 typedef struct {
@@ -33,6 +34,7 @@
 	unsigned char buffer[64];
 	MD5_u32plus block[16];
 } MD5_CTX;
+#endif
 
 /*
  * The basic MD5 functions.
