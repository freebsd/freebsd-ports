--- runtime/flang/async.c.orig	2017-05-17 00:40:01 UTC
+++ runtime/flang/async.c
@@ -27,6 +27,8 @@
  * Fio_asy_close - called from close
  */
 
+#include <sys/signal.h>
+
 #if !defined(INTERIX86) && !defined(TARGET_INTERIX) && !defined(TARGET_OSX) && !defined(CRAY) && !defined(TARGET_WIN_X8632)
 
 #if !defined(TARGET_WIN_X8664)
@@ -44,7 +46,6 @@
 #include "stdioInterf.h"
 #include "async.h"
 
-
 #define FIO_MAX_ASYNC_TRANSACTIONS 16
 
 /* one struct per file */
@@ -320,7 +321,7 @@ Fio_asy_read(struct asy *asy, void *adr,
   asy->aiocb[tn].aio_reqprio = 0;
   asy->aiocb[tn].aio_buf = adr;
   asy->aiocb[tn].aio_nbytes = len;
-  memset(&(asy->aiocb[tn].aio_sigevent), 0, sizeof(sigevent_t));
+  memset(&(asy->aiocb[tn].aio_sigevent), 0, sizeof(struct sigevent));
   asy->aiocb[tn].aio_offset = asy->atd[tn].off;
   n = aio_read(&(asy->aiocb[tn]));
 #endif
@@ -374,7 +375,7 @@ Fio_asy_write(struct asy *asy, void *adr
   asy->aiocb[tn].aio_reqprio = 0;
   asy->aiocb[tn].aio_buf = adr;
   asy->aiocb[tn].aio_nbytes = len;
-  memset(&(asy->aiocb[tn].aio_sigevent), 0, sizeof(sigevent_t));
+  memset(&(asy->aiocb[tn].aio_sigevent), 0, sizeof(struct sigevent));
   asy->aiocb[tn].aio_offset = asy->atd[tn].off;
   n = aio_write(&(asy->aiocb[tn]));
 #endif
