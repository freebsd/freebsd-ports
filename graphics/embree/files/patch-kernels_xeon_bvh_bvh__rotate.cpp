--- kernels/xeon/bvh/bvh_rotate.cpp.orig	2016-05-20 05:45:13 UTC
+++ kernels/xeon/bvh/bvh_rotate.cpp
@@ -104,7 +104,11 @@ namespace embree
 	/*! find best other child */
 	vfloat4 area0123 = vfloat4(extract<0>(min0),extract<0>(min1),extract<0>(min2),extract<0>(min3)) - vfloat4(childArea[c2]);
 	int pos[4] = { pos0,pos1,pos2,pos3 };
-	vbool4 valid = vint4(int(depth+1))+cdepth <= vint4(BVH4::maxBuildDepth); // only select swaps that fulfill depth constraints
+	// Ensure that we have a variable to avoid linking problems on i386.
+	// On amd64 sizeof(size_t) == 8, so previously temporary was created
+	// for the vint4(BVH4::maxBuildDepth) call.
+	const size_t mbd = BVH4::maxBuildDepth;
+	vbool4 valid = vint4(int(depth+1))+cdepth <= vint4(mbd); // only select swaps that fulfill depth constraints
 	valid &= vint4(c2) != vint4(step);
 	if (none(valid)) continue;
 	size_t c1 = select_min(valid,area0123);
