--- links.h.orig	2002-12-26 22:55:21.000000000 +0800
+++ links.h		2002-12-27 13:13:50.000000000 +0800
@@ -3132,6 +3132,7 @@
 unsigned char *get_cp_name(int);
 unsigned char *get_cp_mime_name(int);
 int is_cp_special(int);
+int is_cjk_cp(int);
 void free_conv_table(void);
 unsigned char *encode_utf_8(int);
 int cp2u(unsigned char, int);
