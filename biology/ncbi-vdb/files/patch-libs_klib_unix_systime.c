--- libs/klib/unix/systime.c.orig	2017-07-14 21:55:36 UTC
+++ libs/klib/unix/systime.c
@@ -142,7 +142,7 @@ LIB_EXPORT KTime_t CC KTimeMakeTime ( co
         t . tm_isdst = self -> dst;
 
         ts = mktime ( &t );
-        ts -= timezone;
+        ts += localtime(&ts)->tm_gmtoff;
     }
 
     return ts;
