--- ./src/japanese_tag.h.orig	Fri Jan  5 00:43:02 2001
+++ ./src/japanese_tag.h	Fri Jan  4 04:24:21 2002
@@ -16,6 +16,7 @@
 #ifdef ENABLE_JAPANESE_TAGS
 
 char *to_string_euc(char *str);
+char *to_string_sjis_from_euc(char const *str);
 
 #endif /* ENABLE_JAPANESE_TAGS */
 
