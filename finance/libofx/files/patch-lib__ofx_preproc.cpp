--- lib/ofx_preproc.cpp.orig	2014-09-12 19:26:30 UTC
+++ lib/ofx_preproc.cpp
@@ -310,7 +310,7 @@ int ofx_proc_file(LibofxContextPtr ctx, 
             size_t outbytesleft = inbytesleft * 2 - 1;
             iconv_buffer = (char*) malloc (inbytesleft * 2);
             memset(iconv_buffer, 0, inbytesleft * 2);
-#if defined(OS_WIN32) || defined(__sun)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
             const char * inchar = (const char *)s_buffer.c_str();
 #else
             char * inchar = (char *)s_buffer.c_str();
