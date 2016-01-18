--- libsrc/occ/Partition_Loop2d.cxx.orig	2014-08-29 09:54:03 UTC
+++ libsrc/occ/Partition_Loop2d.cxx
@@ -52,6 +52,10 @@
 #include <gp_Pnt.hxx>
 #include <gp_Pnt2d.hxx>
 
+#ifndef PI
+#define PI        3.14159265358979323846
+#endif
+
 //=======================================================================
 //function : Partition_Loop2d
 //purpose  :
