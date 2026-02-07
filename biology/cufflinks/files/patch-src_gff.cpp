--- src/gff.cpp.orig	2022-07-28 03:24:45 UTC
+++ src/gff.cpp
@@ -21,7 +21,7 @@ const uint gfo_flag_BY_EXON          = 0x00000020; //c
 const uint gfo_flag_DISCARDED        = 0x00000100;
 const uint gfo_flag_LST_KEEP         = 0x00000200;
 const uint gfo_flag_LEVEL_MSK        = 0x00FF0000;
-const byte gfo_flagShift_LEVEL           = 16;
+const bytex gfo_flagShift_LEVEL           = 16;
 
 void gffnames_ref(GffNames* &n) {
   if (n==NULL) n=new GffNames();
