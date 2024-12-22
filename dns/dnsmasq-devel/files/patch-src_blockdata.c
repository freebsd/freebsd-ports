--- src/blockdata.c.orig	2024-12-20 21:57:21 UTC
+++ src/blockdata.c
@@ -193,7 +193,7 @@ void *blockdata_retrieve(struct blockdata *block, size
 {
   size_t blen;
   struct  blockdata *b;
-  void *new, *d;
+  uint8_t *new, *d;
   
   static unsigned int buff_len = 0;
   static unsigned char *buff = NULL;
