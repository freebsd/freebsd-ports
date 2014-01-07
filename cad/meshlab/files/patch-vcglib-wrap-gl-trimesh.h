--- ../../vcglib/wrap/gl/trimesh.h.orig	2013-11-16 21:32:47.000000000 +0100
+++ ../../vcglib/wrap/gl/trimesh.h	2013-11-16 21:33:23.000000000 +0100
@@ -895,6 +895,7 @@
 #define VCTRACE (void)0
 //#define VCTRACE TRACE
 
+/* dead code
 template<class MESH_TYPE>
 void Crease(MESH_TYPE &m, typename MESH_TYPE::scalar_type angleRad)
 {
@@ -1006,6 +1007,7 @@
 	m.vert.math::Swap(newvert);
 	m.vn=m.vert.size();
 }
+*/
 
 /*
 	Secondo tipo di crease angle. ha bisogno del per wedge normal
