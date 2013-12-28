--- src/cwutils/dictionary.h.orig	2013-01-03 17:12:43.000000000 -0500
+++ src/cwutils/dictionary.h	2013-07-15 18:50:15.000000000 -0500
@@ -41,6 +41,7 @@
 
 /* Everything below is deprecated. */
 typedef struct cw_dictionary_s dictionary;
+#if 0
 
 extern int  dictionary_load(const char *file)  __attribute__ ((deprecated("Use cw_dictionaries_read()")));
 extern void dictionary_unload(void)            __attribute__ ((deprecated("Use cw_dictionaries_unload()")));
@@ -51,7 +52,7 @@
 extern const char *get_dictionary_description(const dictionary *dict) __attribute__ ((deprecated("Use cw_dictionary_get_description()")));
 extern int         get_dictionary_group_size(const dictionary *dict)  __attribute__ ((deprecated("Use cw_dictionary_get_group_size()")));
 extern const char *get_dictionary_random_word(const dictionary *dict) __attribute__ ((deprecated("Use cw_dictionary_get_random_word()")));
-
+#endif
 #if defined(__cplusplus)
 }
 #endif
