--- lib/replace/replace.c.orig	2023-11-22 12:09:13 UTC
+++ lib/replace/replace.c
@@ -560,6 +560,7 @@ long long int rep_strtoll(const char *str, char **endp
 
 
 #ifndef HAVE_STRTOULL
+#warning NO_HAVE_STRTOULL
 unsigned long long int rep_strtoull(const char *str, char **endptr, int base)
 {
 #ifdef HAVE_STRTOUQ
@@ -573,7 +574,9 @@ unsigned long long int rep_strtoull(const char *str, c
 #endif
 }
 #else
+#warning HAVE_STROULL
 #ifdef HAVE_BSD_STRTOLL
+#warning HAVE_BSD_STROLL
 #undef strtoull
 unsigned long long int rep_strtoull(const char *str, char **endptr, int base)
 {
