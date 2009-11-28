--- lib/rxio/NovatelData.cpp.FCS	2009-11-24 09:08:46.000000000 +1100
+++ lib/rxio/NovatelData.cpp	2009-11-24 09:40:31.000000000 +1100
@@ -304,7 +304,9 @@
                      cout << "datasize:" << datasize << endl;
 
                      // read the rest of the record
-                  if(datasize-12 >= 1024) {
+		     // Note: OEM2 The Message byte count equals the total 
+		     // length of the data block including the header.
+                  if(datasize >= sizeof(buffer)) {
                      //FFStreamError fe("Read error - buffer overflow");
                      //GPSTK_THROW(fe);
                      failure = 1;
@@ -440,7 +442,8 @@
                      // ---------------------------------------
                      // read the data message, but don't overwrite the header
                      // first check against buffer overflow
-                  if(datasize-28 >= 1024 || datasize-28 < 0) {
+		     // OEM4 total buffer usage = header+data
+                  if(datasize+28 >= sizeof(buffer)) {
                      //FFStreamError fe("Read error - buffer overflow");
                      //GPSTK_THROW(fe);
                      failure = 1;
