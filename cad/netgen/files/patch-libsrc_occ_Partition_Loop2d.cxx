--- libsrc/occ/Partition_Loop2d.cxx.orig	2012-11-09 16:15:02.000000000 +0100
+++ libsrc/occ/Partition_Loop2d.cxx	2013-05-12 11:41:09.000000000 +0200
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
