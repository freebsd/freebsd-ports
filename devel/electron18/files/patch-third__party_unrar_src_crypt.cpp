--- third_party/unrar/src/crypt.cpp.orig	2022-05-11 07:02:07 UTC
+++ third_party/unrar/src/crypt.cpp
@@ -120,6 +120,8 @@ void GetRnd(byte *RndBuf,size_t BufSize)
     Success=CryptGenRandom(hProvider, (DWORD)BufSize, RndBuf) == TRUE;
     CryptReleaseContext(hProvider, 0);
   }
+#elif defined(__OpenBSD__)
+  arc4random_buf(RndBuf, BufSize);
 #elif defined(_UNIX)
   FILE *rndf = fopen("/dev/urandom", "r");
   if (rndf!=NULL)
