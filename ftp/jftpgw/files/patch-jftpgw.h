--- jftpgw.h~	Sat Feb  2 19:11:30 2002
+++ jftpgw.h	Thu Feb 14 22:29:34 2002
@@ -360,7 +360,9 @@
 char* char_append(const char*, const char*);
 char* char_enclose(const char*, const char*, const char*);
 char* strnulldup(const char*);
+#ifndef HAVE_STRCASESTR
 const char* strcasestr(const char* haystack, const char* needle);
+#endif
 
 /* from config.c */
 int config_read_options(FILE*);
