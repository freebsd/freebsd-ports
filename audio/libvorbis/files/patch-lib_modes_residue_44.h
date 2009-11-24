$FreeBSD$
--- lib/modes/residue_44.h.orig	2009-07-09 11:12:08.000000000 +0200
+++ lib/modes/residue_44.h	2009-11-24 21:46:47.000000000 +0100
@@ -22,7 +22,7 @@
 /***** residue backends *********************************************/
 
 static const vorbis_info_residue0 _residue_44_low={
-  0,-1, -1, 9,-1,
+  0,-1, -1, 9,-1,-1,
   /*  0     1     2     3     4     5     6     7  */
   {0},
   {-1},
@@ -31,7 +31,7 @@ static const vorbis_info_residue0 _resid
 };
 
 static const vorbis_info_residue0 _residue_44_mid={
-  0,-1, -1, 10,-1,
+  0,-1, -1, 10,-1,-1,
   /*  0     1     2     3     4     5     6     7     8  */
   {0},
   {-1},
@@ -40,7 +40,7 @@ static const vorbis_info_residue0 _resid
 };
 
 static const vorbis_info_residue0 _residue_44_high={
-  0,-1, -1, 10,-1,
+  0,-1, -1, 10,-1,-1,
   /*  0     1     2     3     4     5     6     7     8  */
   {0},
   {-1},
