--- ./dcraw.cc.orig	2013-03-20 03:31:38.000000000 +0100
+++ ./dcraw.cc	2014-02-05 22:11:28.000000000 +0100
@@ -9269,7 +9269,7 @@
   strncpy (th->desc, desc, 512);
   strncpy (th->make, make, 64);
   strncpy (th->model, model, 64);
-  strcpy (th->soft, "dcraw v"DCRAW_VERSION);
+  strcpy (th->soft, "dcraw v" DCRAW_VERSION);
   t = localtime (&timestamp);
   sprintf (th->date, "%04d:%02d:%02d %02d:%02d:%02d",
       t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
