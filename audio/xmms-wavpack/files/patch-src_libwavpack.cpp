--- src/libwavpack.cpp.orig	2009-01-12 16:13:13.000000000 +0100
+++ src/libwavpack.cpp	2009-01-12 16:15:30.000000000 +0100
@@ -21,7 +21,7 @@ extern "C" {
 #define M_LN10   2.3025850929940456840179914546843642
 #endif
 
-#define DBG(format, args...) fprintf(stderr, format, ## args)
+#define DBG(format, args...) //fprintf(stderr, format, ## args)
 #define BUFFER_SIZE 256 // read buffer size, in samples
 
 extern "C" InputPlugin * get_iplugin_info(void);
@@ -343,7 +343,7 @@ convertUTF8toLocale(char *utf8)
     size_t in_left = strlen(utf8);
     size_t out_left = 2 * in_left + 1;
     char *buf = (char *)g_malloc(out_left);
-    char *in = utf8;
+    const char *in = utf8;
     char *out = buf;
 
     memset(buf, 0, out_left);
