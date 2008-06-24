--- db_dump.c.orig	2008-06-24 16:10:56.000000000 +0000
+++ db_dump.c	2008-06-24 16:11:14.000000000 +0000
@@ -82,6 +82,8 @@
 
 /*----------------------------------------------------helpers------------*/
 #if BYTE_ORDER == BIG_ENDIAN
+#define bswap_16 bswap16
+#define bswap_32 bswap32
 size_t
 db3_fread (void *ptr, size_t size, size_t nmemb, FILE *stream)
 {
