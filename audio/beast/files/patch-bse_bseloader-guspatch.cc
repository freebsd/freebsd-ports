--- bse/bseloader-guspatch.cc.orig	2008-02-26 23:28:43.000000000 +0100
+++ bse/bseloader-guspatch.cc	2008-02-26 23:29:31.000000000 +0100
@@ -347,7 +347,7 @@
   guint&
   data_offset (int chunk_number)
   {
-    return wdsc.chunks[chunk_number].loader_data[0].uint;
+    return wdsc.chunks[chunk_number].loader_data[0].u_int;
   }
   
   GslWaveFormatType
