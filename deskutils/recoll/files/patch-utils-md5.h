--- utils/md5.h.orig	2015-07-16 19:46:26 UTC
+++ utils/md5.h
@@ -19,6 +19,10 @@
 #define	MD5_DIGEST_LENGTH		16
 #define	MD5_DIGEST_STRING_LENGTH	(MD5_DIGEST_LENGTH * 2 + 1)
 
+typedef uint32_t u_int32_t;
+typedef uint64_t u_int64_t;
+typedef uint8_t u_int8_t;
+
 typedef struct MD5Context {
 	u_int32_t state[4];			/* state */
 	u_int64_t count;			/* number of bits, mod 2^64 */
