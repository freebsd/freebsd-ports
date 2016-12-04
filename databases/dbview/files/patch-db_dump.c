--- db_dump.c.orig	2006-11-27 11:51:25 UTC
+++ db_dump.c
@@ -82,6 +82,8 @@ FILE        *dbfile;
 
 /*----------------------------------------------------helpers------------*/
 #if BYTE_ORDER == BIG_ENDIAN
+#define bswap_16 bswap16
+#define bswap_32 bswap32
 size_t
 db3_fread (void *ptr, size_t size, size_t nmemb, FILE *stream)
 {
