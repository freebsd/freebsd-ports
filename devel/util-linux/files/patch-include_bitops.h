--- include/bitops.h.orig	2023-06-25 21:35:59 UTC
+++ include/bitops.h
@@ -25,7 +25,7 @@
 # define be16toh(x) betoh16(x)
 # define be32toh(x) betoh32(x)
 # define be64toh(x) betoh64(x)
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#elif defined(__NetBSD__) || defined(__DragonFly__)
 # define bswap_16(x) bswap16(x)
 # define bswap_32(x) bswap32(x)
 # define bswap_64(x) bswap64(x)
