--- codecs/dcraw.h.orig	2013-10-22 14:00:07 UTC
+++ codecs/dcraw.h
@@ -775,7 +775,8 @@ struct jhead {
 
 int CLASS ljpeg_start (struct jhead *jh, int info_only)
 {
-  int c, tag, len;
+  int c,tag;
+  ushort len;
   uchar data[0x10000];
   const uchar *dp;
 
@@ -786,8 +787,9 @@ int CLASS ljpeg_start (struct jhead *jh,
   do {
     fread (data, 2, 2, ifp);
     tag =  data[0] << 8 | data[1];
-    len = (data[2] << 8 | data[3]) - 2;
-    if (tag <= 0xff00) return 0;
+    len = (data[2] << 8 | data[3]);
+    if (tag <= 0xff00 || len <= 2) return 0;
+    len -= 2;
     fread (data, 1, len, ifp);
     switch (tag) {
       case 0xffc3:
