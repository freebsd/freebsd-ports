--- dcmtls/libsrc/tlslayer.cc.orig	2010-10-14 13:14:46 UTC
+++ dcmtls/libsrc/tlslayer.cc
@@ -371,7 +371,9 @@ void DcmTLSTransportLayer::seedPRNG(cons
 #endif
   if (randFile)
   {
+#ifndef LIBRESSL_VERSION_NUMBER
     if (RAND_egd(randFile) <= 0)
+#endif
     {
       RAND_load_file(randFile ,-1);
     }
