--- simon1decr.c.orig	Mon Apr 12 00:10:19 2004
+++ simon1decr.c	Tue Jan  4 15:36:39 2005
@@ -26,14 +26,9 @@
 
 #define EndGetM32(a)  ((((a)[0])<<24)|(((a)[1])<<16)|(((a)[2])<<8)|((a)[3]))
 
-#define SD_GETBIT(var) do { \
-  if (!bits--) { s -= 4; if (s < src) return 0; bb=EndGetM32(s); bits=31; } \
-  (var) = bb & 1; bb >>= 1; \
-} while (0)
+#define SD_GETBIT(var) do { if (!bits--) { s -= 4; if (s < src) return 0; bb=EndGetM32(s); bits=31; } (var) = bb & 1; bb >>= 1; } while (0)
 
-#define SD_GETBITS(var, nbits) do { \
-  bc=(nbits); (var)=0; while (bc--) {(var)<<=1; SD_GETBIT(bit); (var)|=bit; } \
-} while (0)
+#define SD_GETBITS(var, nbits) do { bc=(nbits); (var)=0; while (bc--) {(var)<<=1; SD_GETBIT(bit); (var)|=bit; } } while (0)
 
 #define SD_TYPE_LITERAL (0)
 #define SD_TYPE_MATCH   (1)
