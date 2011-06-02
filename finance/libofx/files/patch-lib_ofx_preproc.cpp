--- ./lib/ofx_preproc.cpp.orig	2011-04-16 13:10:20.000000000 -0400
+++ ./lib/ofx_preproc.cpp	2011-04-21 11:03:43.000000000 -0400
@@ -228,7 +228,7 @@
           memset(iconv_buffer, 0, READ_BUFFER_SIZE * 2);
           size_t inbytesleft = strlen(s_buffer.c_str());
           size_t outbytesleft = READ_BUFFER_SIZE * 2 - 1;
-#ifdef OS_WIN32
+#if defined(OS_WIN32) || defined(OS_FREEBSD)
           const char * inchar = (const char *)s_buffer.c_str();
 #else
           char * inchar = (char *)s_buffer.c_str();
