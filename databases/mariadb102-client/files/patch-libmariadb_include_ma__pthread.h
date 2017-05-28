--- libmariadb/include/ma_pthread.h.orig	2017-04-04 19:11:32 UTC
+++ libmariadb/include/ma_pthread.h
@@ -23,6 +23,7 @@
 
 #undef SAFE_MUTEX
 
+#include <pthread.h>
 #include <errno.h>
 #ifndef ETIME
 #define ETIME ETIMEDOUT				/* For FreeBSD */
