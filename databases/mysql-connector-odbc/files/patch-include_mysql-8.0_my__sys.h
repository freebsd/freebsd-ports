--- include/mysql-8.0/my_sys.h.orig	2025-06-19 12:19:21 UTC
+++ include/mysql-8.0/my_sys.h
@@ -41,8 +41,12 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 #include "my_config.h"
 
 #ifdef HAVE_ALLOCA_H
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+#include <stdlib.h>
+#else
 #include <alloca.h>
 #endif
+#endif
 #include <limits.h>
 #ifdef _WIN32
 #include <malloc.h>
@@ -332,6 +336,8 @@ typedef int (*IO_CACHE_CALLBACK)(IO_CACHE *);
 
 struct IO_CACHE;
 typedef int (*IO_CACHE_CALLBACK)(IO_CACHE *);
+
+typedef unsigned long ulong;
 
 struct IO_CACHE_SHARE {
   mysql_mutex_t mutex;      /* To sync on reads into buffer. */
