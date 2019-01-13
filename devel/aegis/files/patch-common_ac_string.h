--- common/ac/string.h.orig	2012-12-04 02:03:33 UTC
+++ common/ac/string.h
@@ -128,10 +128,12 @@ size_t strlcat(char *dst, const char *sr
 char *strendcpy(char *dst, const char *src, const char *end);
 #endif
 
+/*
 #undef strcat
 #define strcat strcat_is_unsafe__use_strendcat_instead@
 #undef strcpy
 #define strcpy strcpy_is_unsafe__use_strendcpy_instead@
+*/
 
 #ifndef HAVE_MEMMEM
 void *memmem(const void *, size_t, const void *, size_t);
