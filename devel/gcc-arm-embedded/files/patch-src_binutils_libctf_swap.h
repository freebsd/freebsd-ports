--- src/binutils/libctf/swap.h.orig	2019-09-20 06:03:34 UTC
+++ src/binutils/libctf/swap.h
@@ -28,13 +28,13 @@
 #else
 
 /* Provide our own versions of the byteswap functions.  */
-inline uint16_t
+static inline uint16_t
 bswap_16 (uint16_t v)
 {
   return ((v >> 8) & 0xff) | ((v & 0xff) << 8);
 }
 
-inline uint32_t
+static inline uint32_t
 bswap_32 (uint32_t v)
 {
   return (  ((v & 0xff000000) >> 24)
@@ -43,13 +43,13 @@ bswap_32 (uint32_t v)
 	  | ((v & 0x000000ff) << 24));
 }
 
-inline uint64_t
+static inline uint64_t
 bswap_identity_64 (uint64_t v)
 {
   return v;
 }
 
-inline uint64_t
+static inline uint64_t
 bswap_64 (uint64_t v)
 {
   return (  ((v & 0xff00000000000000ULL) >> 56)
