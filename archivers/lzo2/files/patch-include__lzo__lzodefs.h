--- ./include/lzo/lzodefs.h.orig	2014-06-25 15:47:13.000000000 +0200
+++ ./include/lzo/lzodefs.h	2014-06-27 06:31:33.000000000 +0200
@@ -29,6 +29,8 @@
 #ifndef __LZODEFS_H_INCLUDED
 #define __LZODEFS_H_INCLUDED 1
 
+#include <limits.h>
+
 #if defined(__CYGWIN32__) && !defined(__CYGWIN__)
 #  define __CYGWIN__ __CYGWIN32__
 #endif
