--- lib/rxio/NovatelData.hpp.FCS	2009-11-24 09:08:58.000000000 +1100
+++ lib/rxio/NovatelData.hpp	2009-11-24 09:09:34.000000000 +1100
@@ -165,7 +165,7 @@
 
    private:
          /// private data members
-      unsigned char buffer[1024];   ///< buffer for raw data
+      unsigned char buffer[2048];   ///< buffer for raw data
 
          /// Reference GPS week, for OEM2, where the nav records require a GPS week,
          /// but only the obs records have one, and then it is 10-bit.
