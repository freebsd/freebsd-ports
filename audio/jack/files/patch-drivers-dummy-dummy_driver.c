--- drivers/dummy/dummy_driver.c.orig	2009-02-12 04:44:04.000000000 +0100
+++ drivers/dummy/dummy_driver.c	2009-02-12 04:44:15.000000000 +0100
@@ -73,7 +73,7 @@
         }
 }
 
-#ifdef HAVE_CLOCK_GETTIME
+#if HAVE_CLOCK_GETTIME
 static inline unsigned long long ts_to_nsec(struct timespec ts)
 {
     return ts.tv_sec * 1000000000LL + ts.tv_nsec;
