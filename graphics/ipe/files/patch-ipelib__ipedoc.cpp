--- ipelib/ipedoc.cpp.orig	2013-03-15 13:37:02.000000000 +0000
+++ ipelib/ipedoc.cpp
@@ -41,6 +41,7 @@
 #include "ipelatex.h"
 
 #include <errno.h>
+#include <sys/param.h>
 
 #ifdef IPE_USE_ICONV
 #include <iconv.h>
@@ -850,7 +851,12 @@ int Document::runLatex(String &texLog)
     if (!file)
       return ErrWritingSource;
 
+#if defined(__FreeBSD__) || \
+   (defined(__DragonFly__) && __DragonFly_version > 300502)
+    const char *inbuf = utf8.data();
+#else
     char *inbuf = (char *) utf8.data();
+#endif
     size_t inbytesleft = utf8.size();
 
     FileStream fstream(file);
