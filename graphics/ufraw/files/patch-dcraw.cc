--- dcraw.cc.orig	2015-06-16 03:58:38 UTC
+++ dcraw.cc
@@ -9240,13 +9240,13 @@ canon_a5:
       filters = 0x16161616;
     }
     if (make[0] == 'O') {
-      i = find_green (12, 32, 1188864, 3576832);
-      c = find_green (12, 32, 2383920, 2387016);
-      if (abs(i) < abs(c)) {
-	SWAP(i,c);
+      float g1 = find_green (12, 32, 1188864, 3576832);
+      float g2 = find_green (12, 32, 2383920, 2387016);
+      if (fabsf(g1) < fabsf(g2)) {
+	SWAP(g1,g2);
 	load_flags = 24;
       }
-      if ((int) i < 0) filters = 0x61616161;
+      if (g1 < 0) filters = 0x61616161;
     }
   } else if (fsize == 5869568) {
     if (!timestamp && minolta_z2()) {
@@ -10073,7 +10073,7 @@ void CLASS tiff_head (struct tiff_hdr *th, int full)
   strncpy (th->desc, desc, 512);
   strncpy (th->make, make, 64);
   strncpy (th->model, model, 64);
-  strcpy (th->soft, "dcraw v"DCRAW_VERSION);
+  strcpy (th->soft, "dcraw v" DCRAW_VERSION);
   t = localtime (&timestamp);
   sprintf (th->date, "%04d:%02d:%02d %02d:%02d:%02d",
       t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
