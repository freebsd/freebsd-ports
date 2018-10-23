--- src/common_string.h.orig	2018-08-21 09:40:24 UTC
+++ src/common_string.h
@@ -82,7 +82,9 @@ EXTERN_MSC char *stresep (char **stringp
 
 EXTERN_MSC int gmt_match_string_in_file (const char *filename, const char *string);
 
+#ifndef __FreeBSD__
 EXTERN_MSC char *basename(char *path);
+#endif
 
 #ifdef __cplusplus
 }
