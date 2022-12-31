--- libs/indibase/dsp/dspinterface.cpp.orig	2022-05-21 13:52:23 UTC
+++ libs/indibase/dsp/dspinterface.cpp
@@ -336,9 +336,9 @@ dsp_stream_p Interface::loadFITS(char* buffer, int len
     long ndims;
     long bits_per_sample;
     int status;
-    off_t offset;
-    off_t head;
-    off_t end;
+    OFF_T offset;
+    OFF_T head;
+    OFF_T end;
     fitsfile *fptr;
     void* buf;
     char error_status[MAXINDINAME];
