--- sbagen.c.orig	2011-08-08 00:12:21 UTC
+++ sbagen.c
@@ -141,7 +141,7 @@
 #endif
 
 #ifdef OSS_AUDIO
- #include <linux/soundcard.h>
+ #include <sys/soundcard.h>
  //WAS: #include <sys/soundcard.h>
 #endif
 #ifdef WIN_AUDIO
@@ -181,7 +181,7 @@ void debug(char *fmt, ...) ;
 void warn(char *fmt, ...) ;
 void * Alloc(size_t len) ;
 char * StrDup(char *str) ;
-inline int calcNow() ;
+static inline int calcNow() ;
 void loop() ;
 void outChunk() ;
 void corrVal(int ) ;
@@ -1207,7 +1207,7 @@ setupRefTime() {
   time_ref_ms= 1000*tt->tm_sec + 60000*tt->tm_min + 3600000*tt->tm_hour;
 }  
 
-inline int  
+static inline int  
 calcNow() {
   struct timeval tv;
   if (0 != gettimeofday(&tv, 0)) error("Can't get current time");
