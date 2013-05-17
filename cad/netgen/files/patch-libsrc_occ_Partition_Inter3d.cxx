--- libsrc/occ/Partition_Inter3d.cxx.orig	2012-11-09 16:15:02.000000000 +0100
+++ libsrc/occ/Partition_Inter3d.cxx	2013-05-12 11:31:45.000000000 +0200
@@ -243,8 +243,8 @@
       Standard_Integer i, nbExt = anExtPS.NbExt();
       Extrema_POnSurf aPOnSurf;
       for (i = 1; i <= nbExt; ++i )
-	if (anExtPS.Value( i ) <= TolE)               // V6.3
-	  // if (anExtPS.SquareDistance( i ) <= TolE)   // V6.5
+	// if (anExtPS.Value( i ) <= TolE)               // V6.3
+	  if (anExtPS.SquareDistance( i ) <= TolE)   // V6.5
 	  {
           aPOnSurf = anExtPS.Point( i );
           break;
