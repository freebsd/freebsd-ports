--- src/zm.c.orig	2026-10-03 15:56:10 UTC
+++ src/zm.c
@@ -257,7 +257,7 @@ zdlread2(int c)
  * Send character c with ZMODEM escape sequence encoding.
  *  Escape XON, XOFF. Escape CR following @ (Telenet net escape)
  */
-static inline void 
+static inline LRZSZ_ALWAYS_INLINE void 
 zsendline(int c)
 {
 
@@ -476,7 +476,7 @@ zsda32(const char *buf, size_t length, int frameend)
 	int c;
 	unsigned long crc;
 	int i;
-	DPRINTF(DEBUG_PROTOCOL, "zsdat32: %lu %s", length, Zendnames[(frameend-ZCRCE)&3]);
+	DPRINTF(DEBUG_PROTOCOL, "zsdat32: %zu %s", length, Zendnames[(frameend-ZCRCE)&3]);
 
 	crc = 0xFFFFFFFFL;
         stats_msg_valid(length);
