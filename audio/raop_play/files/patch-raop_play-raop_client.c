--- raop_play/raop_client.c.orig	Thu Jul 28 04:43:18 2005
+++ raop_play/raop_client.c	Fri Aug 12 09:31:35 2005
@@ -24,7 +24,7 @@
 #include <openssl/rsa.h>
 #include <openssl/engine.h>
 
-#include <asm/types.h>
+#include <sys/types.h>
 #include "aexcl_lib.h"
 #include "rtsp_client.h"
 #include "raop_client.h"
@@ -87,7 +87,7 @@
 	return size;
 }
 
-static int encrypt(raopcl_data_t *raopcld, __u8 *data, int size)
+static int raop_encrypt(raopcl_data_t *raopcld, __u8 *data, int size)
 {
 	__u8 *buf;
 	//__u8 tmp[16];
@@ -222,7 +222,7 @@
 	raopcld->data[2]=len>>8;
 	raopcld->data[3]=len&0xff;
 	memcpy(raopcld->data+header_size,sample,count);
-	encrypt(raopcld, raopcld->data+header_size, count);
+	raop_encrypt(raopcld, raopcld->data+header_size, count);
 	len=count+header_size;
 	raopcld->wblk_remsize=count+header_size;
 	raopcld->wblk_wsize=0;
