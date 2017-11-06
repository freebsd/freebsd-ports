--- include/lzo/lzodefs.h.orig	2017-03-01 19:54:14 UTC
+++ include/lzo/lzodefs.h
@@ -29,6 +29,8 @@
 #ifndef __LZODEFS_H_INCLUDED
 #define __LZODEFS_H_INCLUDED 1
 
+#include <limits.h>
+
 #if defined(__CYGWIN32__) && !defined(__CYGWIN__)
 #  define __CYGWIN__ __CYGWIN32__
 #endif
