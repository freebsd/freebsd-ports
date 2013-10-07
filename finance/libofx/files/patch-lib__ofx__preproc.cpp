--- ./lib/ofx_preproc.cpp.orig	2013-04-25 14:06:29.000000000 -0400
+++ ./lib/ofx_preproc.cpp	2013-10-04 06:27:25.000000000 -0400
@@ -310,7 +310,7 @@
             size_t outbytesleft = inbytesleft * 2 - 1;
             iconv_buffer = (char*) malloc (inbytesleft * 2);
             memset(iconv_buffer, 0, inbytesleft * 2);
-#if defined(OS_WIN32) || defined(__sun)
+#if defined(OS_WIN32) || defined(__sun) || defined(__FreeBSD__)
             const char * inchar = (const char *)s_buffer.c_str();
 #else
             char * inchar = (char *)s_buffer.c_str();
