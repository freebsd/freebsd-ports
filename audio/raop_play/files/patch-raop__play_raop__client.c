--- raop_play/raop_client.c.orig	2005-12-16 14:17:01 UTC
+++ raop_play/raop_client.c
@@ -24,7 +24,7 @@
 #include <openssl/rsa.h>
 #include <openssl/engine.h>
 
-#include <asm/types.h>
+#include <sys/types.h>
 #include "aexcl_lib.h"
 #include "rtsp_client.h"
 #include "raop_client.h"
@@ -93,7 +93,7 @@ static int rsa_encrypt(__u8 *text, int l
 	return size;
 }
 
-static int encrypt(raopcl_data_t *raopcld, __u8 *data, int size)
+static int raop_encrypt(raopcl_data_t *raopcld, __u8 *data, int size)
 {
 	__u8 *buf;
 	//__u8 tmp[16];
@@ -260,7 +260,7 @@ int raopcl_send_sample(raopcl_t *p, __u8
 	raopcld->data[2]=len>>8;
 	raopcld->data[3]=len&0xff;
 	memcpy(raopcld->data+header_size,sample,count);
-	encrypt(raopcld, raopcld->data+header_size, count);
+	raop_encrypt(raopcld, raopcld->data+header_size, count);
 	len=count+header_size;
 	raopcld->wblk_remsize=count+header_size;
 	raopcld->wblk_wsize=0;
