--- src/gff.h.orig	2022-07-28 03:20:26 UTC
+++ src/gff.h
@@ -42,7 +42,7 @@ extern const uint gfo_flag_DISCARDED; //should not be 
 extern const uint gfo_flag_LST_KEEP; //GffObj from GffReader::gflst is to be kept (not deallocated)
                                      //when GffReader is destroyed
 extern const uint gfo_flag_LEVEL_MSK; //hierarchical level: 0 = no parent
-extern const byte gfo_flagShift_LEVEL;
+extern const bytex gfo_flagShift_LEVEL;
 
 extern bool gff_show_warnings;
 
@@ -508,18 +508,18 @@ class GffObj:public GSeg { (public)
     if (v) flags |= gfo_flag_CHILDREN_PROMOTED;
       else flags &= ~gfo_flag_CHILDREN_PROMOTED;
      }
-  void setLevel(byte v) {
+  void setLevel(bytex v) {
     if (v==0) flags &= ~gfo_flag_LEVEL_MSK;
          else flags &= ~(((uint)v) << gfo_flagShift_LEVEL);
     }
-  byte incLevel() {
+  bytex incLevel() {
     uint v=((flags & gfo_flag_LEVEL_MSK) >> gfo_flagShift_LEVEL);
     v++;
     flags &= ~(v << gfo_flagShift_LEVEL);
     return v;
     }
-  byte getLevel() {
-    return ((byte)((flags & gfo_flag_LEVEL_MSK) >> gfo_flagShift_LEVEL));
+  bytex getLevel() {
+    return ((bytex)((flags & gfo_flag_LEVEL_MSK) >> gfo_flagShift_LEVEL));
     }
 
   bool isValidTranscript() { 
