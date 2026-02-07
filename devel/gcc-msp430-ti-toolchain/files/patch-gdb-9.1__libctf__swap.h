--- gdb-9.1/libctf/swap.h.orig	2020-01-18 16:55:48.000000000 +0300
+++ gdb-9.1/libctf/swap.h	2020-08-21 16:27:33.859237620 +0300
@@ -43,7 +43,7 @@
 	  | ((v & 0x000000ff) << 24));
 }
 
-inline uint64_t
+static inline uint64_t
 bswap_identity_64 (uint64_t v)
 {
   return v;
