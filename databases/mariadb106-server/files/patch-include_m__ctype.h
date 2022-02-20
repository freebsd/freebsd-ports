--- include/m_ctype.h.orig	2021-08-04 18:00:35 UTC
+++ include/m_ctype.h
@@ -43,6 +43,10 @@ extern "C" {
 
 #define CHARSET_DIR	"charsets/"
 
+#ifndef ulong
+typedef unsigned long ulong;
+#endif
+
 #define my_wc_t ulong
 
 #define MY_CS_REPLACEMENT_CHARACTER 0xFFFD
