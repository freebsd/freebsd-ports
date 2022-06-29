--- third_party/sqlite/src/amalgamation/sqlite3.c.orig	2022-05-25 04:04:35 UTC
+++ third_party/sqlite/src/amalgamation/sqlite3.c
@@ -41443,7 +41443,12 @@ static int unixRandomness(sqlite3_vfs *NotUsed, int nB
   memset(zBuf, 0, nBuf);
   randomnessPid = osGetpid(0);
 #if !defined(SQLITE_TEST) && !defined(SQLITE_OMIT_RANDOMNESS)
+#if defined(__OpenBSD__)
   {
+    arc4random_buf(zBuf, nBuf);
+  }
+#else
+  {
     int fd, got;
     fd = robust_open("/dev/urandom", O_RDONLY, 0);
     if( fd<0 ){
@@ -41458,6 +41463,7 @@ static int unixRandomness(sqlite3_vfs *NotUsed, int nB
       robust_close(0, fd, __LINE__);
     }
   }
+#endif
 #endif
   return nBuf;
 }
