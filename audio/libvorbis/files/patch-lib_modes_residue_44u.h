$FreeBSD$
--- lib/modes/residue_44u.h.orig	2009-07-08 07:40:12.000000000 +0200
+++ lib/modes/residue_44u.h	2009-11-24 21:46:47.000000000 +0100
@@ -23,7 +23,7 @@
 
 
 static const vorbis_info_residue0 _residue_44_low_un={
-  0,-1, -1, 8,-1,
+  0,-1, -1, 8,-1,-1,
   {0},
   {-1},
   {  .5,  1.5,  1.5,  2.5,  2.5,  4.5, 28.5},
@@ -31,7 +31,7 @@ static const vorbis_info_residue0 _resid
 };
 
 static const vorbis_info_residue0 _residue_44_mid_un={
-  0,-1, -1, 10,-1,
+  0,-1, -1, 10,-1,-1,
   /*  0     1     2     3     4     5     6     7     8     9 */
   {0},
   {-1},
@@ -40,7 +40,7 @@ static const vorbis_info_residue0 _resid
 };
 
 static const vorbis_info_residue0 _residue_44_hi_un={
-  0,-1, -1, 10,-1,
+  0,-1, -1, 10,-1,-1,
   /*  0     1     2     3     4     5     6     7     8     9 */
   {0},
   {-1},
