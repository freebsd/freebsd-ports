--- libctf/swap.h.orig	2020-02-27 15:22:32.550650000 -0800
+++ libctf/swap.h	2020-02-27 15:22:43.397285000 -0800
@@ -43,7 +43,7 @@ bswap_32 (uint32_t v)
 	  | ((v & 0x000000ff) << 24));
 }
 
-inline uint64_t
+static inline uint64_t
 bswap_identity_64 (uint64_t v)
 {
   return v;
