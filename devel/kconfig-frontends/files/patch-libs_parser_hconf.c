--- libs/parser/hconf.c.orig	2019-09-24 15:10:13 UTC
+++ libs/parser/hconf.c
@@ -172,7 +172,7 @@ __attribute__ ((__gnu_inline__))
 #endif
 #endif
 const struct kconf_id *
-kconf_id_lookup (register const char *str, register unsigned int len)
+kconf_id_lookup (register const char *str, register GPERF_LEN_TYPE len)
 {
   enum
     {
