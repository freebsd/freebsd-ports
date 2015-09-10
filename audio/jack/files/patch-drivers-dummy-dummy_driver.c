--- drivers/dummy/dummy_driver.c.orig	2013-10-04 00:45:25 UTC
+++ drivers/dummy/dummy_driver.c
@@ -73,7 +73,7 @@ FakeVideoSync( dummy_driver_t *driver )
         }
 }
 
-#ifdef HAVE_CLOCK_GETTIME
+#if HAVE_CLOCK_GETTIME
 static inline unsigned long long ts_to_nsec(struct timespec ts)
 {
     return ts.tv_sec * 1000000000LL + ts.tv_nsec;
