--- src/common/utils.cpp.orig	Mon Jan 17 07:29:39 2005
+++ src/common/utils.cpp	Thu Aug 11 20:28:47 2005
@@ -37,8 +37,10 @@
   char tmp[100];
   struct tm t;
   struct timeval tv;
+  time_t _clock;
   gettimeofday(&tv,NULL);
-  localtime_r(&tv.tv_sec, &t);
+  _clock = tv.tv_sec;
+  localtime_r(&_clock, &t);
   strftime(tmp,99,"%H:%M:%S",&t);
   sprintf(tmp+8,".%06ld",tv.tv_usec);
   return tmp;
