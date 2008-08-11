--- modules/src/ffmpegoutmodule/ffmpegwriter.cpp.orig	2007-04-29 23:53:40.000000000 +0900
+++ modules/src/ffmpegoutmodule/ffmpegwriter.cpp	2008-08-09 19:33:29.000000000 +0900
@@ -175,7 +175,7 @@
   if (!(fmt->flags & AVFMT_NOFILE)) 
   {
     /* close the output file */
-    url_fclose(&oc->pb);
+    url_fclose(oc->pb);
   }
 
   /* free the stream */
