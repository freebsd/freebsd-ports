--- ./lib/ofx_preproc.cpp.orig	2011-06-08 08:07:52.000000000 -0400
+++ ./lib/ofx_preproc.cpp	2012-02-22 08:46:57.000000000 -0500
@@ -231,7 +231,7 @@
           memset(iconv_buffer, 0, READ_BUFFER_SIZE * 2);
           size_t inbytesleft = strlen(s_buffer.c_str());
           size_t outbytesleft = READ_BUFFER_SIZE * 2 - 1;
-#ifdef OS_WIN32
+#if defined(OS_WIN32) || defined(__FreeBSD__)
           const char * inchar = (const char *)s_buffer.c_str();
 #else
           char * inchar = (char *)s_buffer.c_str();
