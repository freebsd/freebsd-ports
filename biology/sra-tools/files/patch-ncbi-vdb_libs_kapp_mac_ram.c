--- ncbi-vdb/libs/kapp/mac/ram.c.orig	2023-07-10 16:13:36 UTC
+++ ncbi-vdb/libs/kapp/mac/ram.c
@@ -46,7 +46,14 @@ rc_t KAppGetTotalRam ( uint64_t * totalRam )
 
     assert ( totalRam != 0 );
 
+// FIXME: This file should probably be moved to bsd/ram.c
+#if defined(__APPLE__)
     ret = sysctlbyname("hw.memsize", totalRam, &len, NULL, 0 );
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
+    ret = sysctlbyname("hw.usermem", totalRam, &len, NULL, 0 );
+#else
+    #error "You need to add a sysctl for this platform."
+#endif
     if ( ret < 0 )
     {
 		int status = errno;
