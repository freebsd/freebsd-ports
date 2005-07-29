--- /dev/null	Thu Aug  8 22:39:51 2002
+++ external/neon/md5.c.pat	Thu Aug  8 22:35:33 2002
@@ -0,0 +1,109 @@
+*** ..\download\neon-0.14.0\src\md5.c	Sun Apr 29 13:23:08 2001
+--- sub\md5.c	Tue May 08 12:52:02 2001
+***************
+*** 278,290 ****
+       const void *buffer;
+       size_t len;
+       struct md5_ctx *ctx;
+  {
+    md5_uint32 correct_words[16];
+!   const md5_uint32 *words = buffer;
+!   size_t nwords = len / sizeof (md5_uint32);
+!   const md5_uint32 *endp = words + nwords;
+    md5_uint32 A = ctx->A;
+    md5_uint32 B = ctx->B;
+    md5_uint32 C = ctx->C;
+    md5_uint32 D = ctx->D;
+  
+--- 278,289 ----
+       const void *buffer;
+       size_t len;
+       struct md5_ctx *ctx;
+  {
+    md5_uint32 correct_words[16];
+!   const unsigned char *words = buffer;
+!   const unsigned char *endp = words + len;
+    md5_uint32 A = ctx->A;
+    md5_uint32 B = ctx->B;
+    md5_uint32 C = ctx->C;
+    md5_uint32 D = ctx->D;
+  
+***************
+*** 313,324 ****
+  	 we store the swapped words in the array CORRECT_WORDS.  */
+  
+  #define OP(a, b, c, d, s, T)						\
+        do								\
+          {								\
+! 	  a += FF (b, c, d) + (*cwp++ = SWAP (*words)) + T;		\
+! 	  ++words;							\
+  	  CYCLIC (a, s);						\
+  	  a += b;							\
+          }								\
+        while (0)
+  
+--- 312,325 ----
+  	 we store the swapped words in the array CORRECT_WORDS.  */
+  
+  #define OP(a, b, c, d, s, T)						\
+        do								\
+          {								\
+!       md5_uint32 WORD_ = words[0] | (words[1] << 8) \
+! 	                   | (words[2] << 16) | (words[3] << 24); \
+! 	  a += FF (b, c, d) + (*cwp++ = WORD_) + T;		\
+! 	  words += 4;							\
+  	  CYCLIC (a, s);						\
+  	  a += b;							\
+          }								\
+        while (0)
+  
+***************
+*** 431,441 ****
+    ctx->D = D;
+  }
+  
+  /* Writes the ASCII representation of the MD5 digest into the
+   * given buffer, which must be at least 33 characters long. */
+! void ne_md5_to_ascii(const unsigned char md5_buf[16], char *buffer) 
+  {
+      int count;
+      for (count = 0; count<16; count++) {
+  	buffer[count*2] = HEX2ASC(md5_buf[count] >> 4);
+  	buffer[count*2+1] = HEX2ASC(md5_buf[count] & 0x0f);
+--- 432,442 ----
+    ctx->D = D;
+  }
+  
+  /* Writes the ASCII representation of the MD5 digest into the
+   * given buffer, which must be at least 33 characters long. */
+! void ne_md5_to_ascii(const unsigned char md5_buf[16], char *buffer)
+  {
+      int count;
+      for (count = 0; count<16; count++) {
+  	buffer[count*2] = HEX2ASC(md5_buf[count] >> 4);
+  	buffer[count*2+1] = HEX2ASC(md5_buf[count] & 0x0f);
+***************
+*** 443,453 ****
+      buffer[32] = '\0';
+  }
+  
+  /* Reads the ASCII representation of an MD5 digest. The buffer must
+   * be at least 32 characters long. */
+! void ne_ascii_to_md5(const char *buffer, unsigned char md5_buf[16]) 
+  {
+      int count;
+      for (count = 0; count<16; count++) {
+  	md5_buf[count] = ((ASC2HEX(buffer[count*2])) << 4) |
+  	    ASC2HEX(buffer[count*2+1]);
+--- 444,454 ----
+      buffer[32] = '\0';
+  }
+  
+  /* Reads the ASCII representation of an MD5 digest. The buffer must
+   * be at least 32 characters long. */
+! void ne_ascii_to_md5(const char *buffer, unsigned char md5_buf[16])
+  {
+      int count;
+      for (count = 0; count<16; count++) {
+  	md5_buf[count] = ((ASC2HEX(buffer[count*2])) << 4) |
+  	    ASC2HEX(buffer[count*2+1]);
