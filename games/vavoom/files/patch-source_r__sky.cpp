--- source/r_sky.cpp.orig	2017-06-04 15:57:26.347510000 +0200
+++ source/r_sky.cpp	2017-06-04 16:05:26.710124000 +0200
@@ -223,9 +223,9 @@
 			s.surf.verts[0] = TVec(cosa0 * vradius, sina0 * vradius, bheight);
 			s.surf.verts[1] = TVec(cosa0 * tradius, sina0 * tradius, theight);
 			s.surf.verts[2] = TVec(cosa1 * tradius, sina1 * tradius, theight);
-			s.surf.verts[3] = TVec(cosa1 * vradius, sina1 * vradius, bheight);
+			s.plane.normal = TVec(cosa1 * vradius, sina1 * vradius, bheight);
 
-			TVec hdir = j < VDIVS / 2 ? s.surf.verts[3] - s.surf.verts[0] :
+			TVec hdir = j < VDIVS / 2 ? s.plane.normal - s.surf.verts[0] :
 				s.surf.verts[2] - s.surf.verts[1];
 			TVec vdir = s.surf.verts[0] - s.surf.verts[1];
 			TVec normal = Normalise(CrossProduct(vdir, hdir));
@@ -336,32 +336,32 @@
 	sky[0].surf.verts[0] = TVec(128, 128, -128);
 	sky[0].surf.verts[1] = TVec(128, 128, 128);
 	sky[0].surf.verts[2] = TVec(128, -128, 128);
-	sky[0].surf.verts[3] = TVec(128, -128, -128);
+	sky[0].plane.normal = TVec(128, -128, -128);
 
 	sky[1].surf.verts[0] = TVec(128, -128, -128);
 	sky[1].surf.verts[1] = TVec(128, -128, 128);
 	sky[1].surf.verts[2] = TVec(-128, -128, 128);
-	sky[1].surf.verts[3] = TVec(-128, -128, -128);
+	sky[1].plane.normal = TVec(-128, -128, -128);
 
 	sky[2].surf.verts[0] = TVec(-128, -128, -128);
 	sky[2].surf.verts[1] = TVec(-128, -128, 128);
 	sky[2].surf.verts[2] = TVec(-128, 128, 128);
-	sky[2].surf.verts[3] = TVec(-128, 128, -128);
+	sky[2].plane.normal = TVec(-128, 128, -128);
 
 	sky[3].surf.verts[0] = TVec(-128, 128, -128);
 	sky[3].surf.verts[1] = TVec(-128, 128, 128);
 	sky[3].surf.verts[2] = TVec(128, 128, 128);
-	sky[3].surf.verts[3] = TVec(128, 128, -128);
+	sky[3].plane.normal = TVec(128, 128, -128);
 
 	sky[4].surf.verts[0] = TVec(128.0, 128.0, 128);
 	sky[4].surf.verts[1] = TVec(-128.0, 128.0, 128);
 	sky[4].surf.verts[2] = TVec(-128.0, -128.0, 128);
-	sky[4].surf.verts[3] = TVec(128.0, -128.0, 128);
+	sky[4].plane.normal = TVec(128.0, -128.0, 128);
 
 	sky[5].surf.verts[0] = TVec(128, 128, -128);
 	sky[5].surf.verts[1] = TVec(128, -128, -128);
 	sky[5].surf.verts[2] = TVec(-128, -128, -128);
-	sky[5].surf.verts[3] = TVec(-128, 128, -128);
+	sky[5].plane.normal = TVec(-128, 128, -128);
 
 	sky[0].plane.Set(TVec(-1, 0, 0), -128);
 	sky[0].texinfo.saxis = TVec(0, -1.0, 0);
