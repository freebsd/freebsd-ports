
$FreeBSD$

--- lib/ofx_preproc.cpp.orig	2008-12-07 07:22:57.000000000 +0900
+++ lib/ofx_preproc.cpp	2009-03-16 03:31:53.000000000 +0900
@@ -23,6 +23,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string>
+#include <unistd.h>
 #include "ParserEventGeneratorKit.h"
 #include "libofx.h"
 #include "messages.hh"
@@ -185,7 +186,7 @@
 	    memset(iconv_buffer,0,READ_BUFFER_SIZE * 2);
 	    size_t inbytesleft = strlen(s_buffer.c_str());
 	    size_t outbytesleft = READ_BUFFER_SIZE * 2 - 1;
-#ifdef OS_WIN32
+#if defined(OS_WIN32) || defined(OS_FREEBSD)
 	    const char * inchar = (const char *)s_buffer.c_str();
 #else
 	    char * inchar = (char *)s_buffer.c_str();
