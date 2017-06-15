--- src/libfaketime.c.orig	2016-06-27 06:54:00 UTC
+++ src/libfaketime.c
@@ -23,6 +23,17 @@
 
 #define _GNU_SOURCE             /* required to get RTLD_NEXT defined */
 
+/*
+ * libfaketime.c:1246:5: error: conflicting types for 'gettimeofday'
+ * int gettimeofday(struct timeval *tv, void *tz)
+ * vs
+ * int gettimeofday(struct timeval *, struct timezone *);
+ */
+
+#define gettimeofday bsd_gettimeofday
+#include <sys/time.h>
+#undef gettimeofday
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
@@ -58,6 +69,8 @@
 extern char *__progname;
 #ifdef __sun
 #include "sunos_endian.h"
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
 #else
 #include <endian.h>
 #endif
