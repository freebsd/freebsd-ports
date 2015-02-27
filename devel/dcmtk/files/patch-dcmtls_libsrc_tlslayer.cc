--- dcmtls/libsrc/tlslayer.cc.orig	2010-10-14 15:14:46.000000000 +0200
+++ dcmtls/libsrc/tlslayer.cc	2015-02-27 10:49:40.350424950 +0100
@@ -371,10 +371,7 @@
 #endif
   if (randFile)
   {
-    if (RAND_egd(randFile) <= 0)
-    {
-      RAND_load_file(randFile ,-1);
-    }
+    RAND_load_file(randFile ,-1);
   }
   if (RAND_status()) canWriteRandseed = OFTrue;
   else
