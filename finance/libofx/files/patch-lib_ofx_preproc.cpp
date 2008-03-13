
$FreeBSD$

--- lib/ofx_preproc.cpp.orig	Mon Nov 12 15:07:48 2007
+++ lib/ofx_preproc.cpp	Thu Jan 17 02:39:31 2008
@@ -23,6 +23,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string>
+#include <unistd.h>
 #include "ParserEventGeneratorKit.h"
 #include "libofx.h"
 #include "messages.hh"
@@ -185,7 +186,7 @@
 	    memset(iconv_buffer,0,READ_BUFFER_SIZE);
 	    size_t inbytesleft = strlen(s_buffer.c_str());
 	    size_t outbytesleft = READ_BUFFER_SIZE;
-#ifdef OS_WIN32
+#if defined(OS_WIN32) || defined(OS_FREEBSD)
 	    const char * inchar = (const char *)s_buffer.c_str();
 #else
 	    char * inchar = (char *)s_buffer.c_str();
