--- Source/ThirdParty/StanHull/hull.cpp.orig	2019-05-24 15:51:45 UTC
+++ Source/ThirdParty/StanHull/hull.cpp
@@ -2587,7 +2587,7 @@ int overhull(Plane *planes,int planes_count,float3 *ve
 			 float3 *&verts_out, int &verts_count_out,  int *&faces_out, int &faces_count_out ,float inflate)
 {
 	int i,j;
-	if(verts_count <4) return NULL;
+	if(verts_count <4) return 0;
 	maxplanes = Min(maxplanes,planes_count);
 	float3 bmin(verts[0]),bmax(verts[0]);
 	for(i=0;i<verts_count;i++) 
