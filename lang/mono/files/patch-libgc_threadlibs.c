--- libgc/threadlibs.c.orig	Wed Jul  7 22:57:48 2004
+++ libgc/threadlibs.c	Wed Jul  7 23:05:12 2004
@@ -1,5 +1,6 @@
 # include "private/gcconfig.h"
 # include <stdio.h>
+# include <sys/param.h>
 
 int main()
 {
@@ -12,7 +13,11 @@
 #   if defined(GC_LINUX_THREADS) || defined(GC_IRIX_THREADS) \
 	|| defined(GC_FREEBSD_THREADS) || defined(GC_SOLARIS_PTHREADS) \
 	|| defined(GC_DARWIN_THREADS) || defined(GC_AIX_THREADS)
+#       if (__FREEBSD_version >= 500000)
         printf("-lpthread\n");
+#       else
+	printf("-pthread\n");
+#       endif
 #   endif
 #   if defined(GC_HPUX_THREADS) || defined(GC_OSF1_THREADS)
 	printf("-lpthread -lrt\n");
