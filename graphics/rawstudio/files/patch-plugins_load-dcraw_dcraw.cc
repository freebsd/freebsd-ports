--- plugins/load-dcraw/dcraw.cc.orig	2015-05-29 01:03:46 UTC
+++ plugins/load-dcraw/dcraw.cc
@@ -869,7 +869,8 @@ struct jhead {
 
 int CLASS ljpeg_start (struct jhead *jh, int info_only)
 {
-  int c, tag, len;
+  int c, tag;
+  ushort len;
   uchar data[0x10000];
   const uchar *dp;
 
