--- kernels/xeon/bvh4/bvh4_rotate.cpp.orig	2015-09-17 06:11:18 UTC
+++ kernels/xeon/bvh4/bvh4_rotate.cpp
@@ -104,7 +104,11 @@ namespace embree
 	/*! find best other child */
 	float4 area0123 = float4(extract<0>(min0),extract<0>(min1),extract<0>(min2),extract<0>(min3)) - float4(childArea[c2]);
 	int pos[4] = { pos0,pos1,pos2,pos3 };
-	bool4 valid = int4(int(depth+1))+cdepth <= int4(BVH4::maxBuildDepth); // only select swaps that fulfill depth constraints
+	// Ensure that we have a variable to avoid linking problems on i386.
+	// On amd64 sizeof(size_t) == 8, so previously temporary was created
+	// for the int4(BVH4::maxBuildDepth) call.
+	const size_t mbd = BVH4::maxBuildDepth;
+	bool4 valid = int4(int(depth+1))+cdepth <= int4(mbd); // only select swaps that fulfill depth constraints
 	valid &= int4(c2) != int4(step);
 	if (none(valid)) continue;
 	size_t c1 = select_min(valid,area0123);
