--- /dev/null	2011-12-22 15:12:10.000000000 +0100
+++ freebsd.h	2011-12-22 15:09:36.970404879 +0100
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
