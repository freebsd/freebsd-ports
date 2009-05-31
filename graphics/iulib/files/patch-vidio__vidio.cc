--- ./vidio/vidio.cc.orig	2008-10-16 03:50:34.000000000 +0900
+++ ./vidio/vidio.cc	2009-05-22 09:19:51.000000000 +0900
@@ -27,7 +27,6 @@
 extern "C" {
 #include <assert.h>
 #include <math.h>
-#include <malloc.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
@@ -481,7 +480,7 @@
             av_freep(&oc->streams[i]);
         }
 
-        url_fclose(&oc->pb);
+        url_fclose(oc->pb);
 
         // free the stream
         av_free(oc);
