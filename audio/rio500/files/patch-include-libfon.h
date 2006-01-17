--- include/libfon.h.orig	Tue Jan 17 14:07:33 2006
+++ include/libfon.h	Tue Jan 17 14:08:42 2006
@@ -34,6 +34,9 @@
 #define MZ_HEADER_MAGIC 0x5a4d
 #define NE_HEADER_MAGIC 0x454e
 
+#define bswap_16(x) (be16toh(x))
+#define bswap_32(x) (be32toh(x))
+
 typedef struct {
    uint16_t magic;
    uint16_t dummy[29];          /* MZ Header data that we want to skip */
