--- ncbi-vdb/libs/klib/unix/systime.c.orig	2023-07-10 16:13:36 UTC
+++ ncbi-vdb/libs/klib/unix/systime.c
@@ -142,7 +142,13 @@ LIB_EXPORT KTime_t CC KTimeMakeTime ( const KTime *sel
         t . tm_isdst = self -> dst;
 
         ts = mktime ( &t );
+#ifdef __FreeBSD__
+	// This might be portable to all platforms
+	ts += localtime(&ts)->tm_gmtoff;
+#else
+	// extern global in sys/time.h on Linux and some other platforms
         ts -= timezone;
+#endif
     }
 
     return ts;
