--- include/iprt/cdefs.h.orig	2018-10-15 14:24:52 UTC
+++ include/iprt/cdefs.h
@@ -2611,28 +2611,28 @@
 
 /** @def RT_BYTE1
  * Gets the first byte of something. */
-#define RT_BYTE1(a)                             ( (a)         & 0xff )
+#define RT_BYTE1(a)                             ( (uint8_t)((a)         & 0xff) )
 /** @def RT_BYTE2
  * Gets the second byte of something. */
-#define RT_BYTE2(a)                             ( ((a) >>  8) & 0xff )
+#define RT_BYTE2(a)                             ( (uint8_t)(((a) >>  8) & 0xff) )
 /** @def RT_BYTE3
  * Gets the second byte of something. */
-#define RT_BYTE3(a)                             ( ((a) >> 16) & 0xff )
+#define RT_BYTE3(a)                             ( (uint8_t)(((a) >> 16) & 0xff) )
 /** @def RT_BYTE4
  * Gets the fourth byte of something. */
-#define RT_BYTE4(a)                             ( ((a) >> 24) & 0xff )
+#define RT_BYTE4(a)                             ( (uint8_t)(((a) >> 24) & 0xff) )
 /** @def RT_BYTE5
  * Gets the fifth byte of something. */
-#define RT_BYTE5(a)                             ( ((a) >> 32) & 0xff )
+#define RT_BYTE5(a)                             ( (uint8_t)(((a) >> 32) & 0xff) )
 /** @def RT_BYTE6
  * Gets the sixth byte of something. */
-#define RT_BYTE6(a)                             ( ((a) >> 40) & 0xff )
+#define RT_BYTE6(a)                             ( (uint8_t)(((a) >> 40) & 0xff) )
 /** @def RT_BYTE7
  * Gets the seventh byte of something. */
-#define RT_BYTE7(a)                             ( ((a) >> 48) & 0xff )
+#define RT_BYTE7(a)                             ( (uint8_t)(((a) >> 48) & 0xff) )
 /** @def RT_BYTE8
  * Gets the eight byte of something. */
-#define RT_BYTE8(a)                             ( ((a) >> 56) & 0xff )
+#define RT_BYTE8(a)                             ( (uint8_t)(((a) >> 56) & 0xff) )
 
 
 /** @def RT_LODWORD
