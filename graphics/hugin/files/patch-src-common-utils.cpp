--- src/common/utils.cpp.orig   Wed Mar  2 22:15:55 2005
+++ src/common/utils.cpp        Wed Mar  2 22:16:30 2005
@@ -38,7 +38,7 @@
   struct tm t;
   struct timeval tv;
   gettimeofday(&tv,NULL);
-  localtime_r(&tv.tv_sec, &t);
+  localtime_r((time_t *)&tv.tv_sec, &t);
   strftime(tmp,99,"%H:%M:%S",&t);
   sprintf(tmp+8,".%06ld",tv.tv_usec);
   return tmp;
