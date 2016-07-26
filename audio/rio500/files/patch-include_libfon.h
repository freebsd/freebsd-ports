--- include/libfon.h.orig	2000-05-21 23:01:46 UTC
+++ include/libfon.h
@@ -34,6 +34,9 @@
 #define MZ_HEADER_MAGIC 0x5a4d
 #define NE_HEADER_MAGIC 0x454e
 
+#define bswap_16(x) (be16toh(x))
+#define bswap_32(x) (be32toh(x))
+
 typedef struct {
    uint16_t magic;
    uint16_t dummy[29];          /* MZ Header data that we want to skip */
