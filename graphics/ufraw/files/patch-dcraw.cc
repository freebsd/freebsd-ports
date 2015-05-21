--- dcraw.cc.orig	2015-01-30 15:15:16.000000000 +0000
+++ dcraw.cc	2015-05-14 19:29:47.000000000 +0000
@@ -934,7 +934,8 @@
 
 int CLASS ljpeg_start (struct jhead *jh, int info_only)
 {
-  int c, tag, len;
+  int c, tag;
+  ushort len;
   uchar data[0x10000];
   const uchar *dp;
 
@@ -9715,7 +9716,7 @@
   strncpy (th->desc, desc, 512);
   strncpy (th->make, make, 64);
   strncpy (th->model, model, 64);
-  strcpy (th->soft, "dcraw v"DCRAW_VERSION);
+  strcpy (th->soft, "dcraw v" DCRAW_VERSION);
   t = localtime (&timestamp);
   sprintf (th->date, "%04d:%02d:%02d %02d:%02d:%02d",
       t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
