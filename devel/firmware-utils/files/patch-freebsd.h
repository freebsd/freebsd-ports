--- freebsd.h.orig	2015-08-19 13:19:00 UTC
+++ freebsd.h
@@ -0,0 +1,9 @@
+/*
+ *
+ */
+
+#define	bswap_8(x)	((x) & 0xff)
+#define bswap_16(x)	((bswap_8(x) << 8) | bswap_8((x) >> 8))
+#define	bswap_32(x)	((bswap_16(x) << 16) | bswap_16((x) >> 16))
+#define bswap_64(x)	((bswap_32(x) << 32) | bswap_32((x) >> 32))
+
