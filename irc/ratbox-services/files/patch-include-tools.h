--- include/tools.h.orig	2014-02-21 09:56:56.433232947 -0600
+++ include/tools.h	2014-02-21 09:56:58.518249228 -0600
@@ -26,8 +26,8 @@
 extern const char *lcase(const char *);
 extern const char *ucase(const char *);
 
-__inline int string_to_array(char *string, char *parv[]);
-__inline int string_to_array_delim(char *string, char *parv[], char delim, int maxpara);
+int string_to_array(char *string, char *parv[]);
+int string_to_array_delim(char *string, char *parv[], char delim, int maxpara);
 
 #ifndef HAVE_STRLCAT
 extern size_t strlcat(char *dst, const char *src, size_t siz);
