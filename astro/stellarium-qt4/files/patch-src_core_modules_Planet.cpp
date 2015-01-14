--- src/core/modules/Planet.cpp.orig	2014-10-11 11:24:38 UTC
+++ src/core/modules/Planet.cpp
@@ -879,13 +879,13 @@ Vec3d Planet::getHeliocentricPos(Vec3d p
 	// 	}
 	// }
 	Vec3d pos = p;
-	const Planet* ourParent = &(*parent);
+	const Planet* ourParent = parent.data();
 	const Planet* parentsParent;
 	// int i = 0;
 	if (NULL != ourParent)
 	{
 		// const Planet* const parentsParent = &(*(ourParent->parent));
-		while (NULL != (parentsParent = &(*(ourParent->parent))))
+		while (NULL != (parentsParent = ourParent->parent.data()))
 		{
 			pos += ourParent->eclipticPos;
 			ourParent = parentsParent;
