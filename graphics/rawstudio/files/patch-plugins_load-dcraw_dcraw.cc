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
 
@@ -8605,7 +8606,7 @@ void CLASS tiff_head (struct tiff_hdr *th, int full)
   strncpy (th->desc, desc, 512);
   strncpy (th->make, make, 64);
   strncpy (th->model, model, 64);
-  strcpy (th->soft, "dcraw v"DCRAW_VERSION);
+  strcpy (th->soft, "dcraw v" DCRAW_VERSION);
   t = gmtime (&timestamp);
   sprintf (th->date, "%04d:%02d:%02d %02d:%02d:%02d",
       t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
