# pioneerLib.dir/src/CollMesh.cpp does not compile on i686 arch
# https://github.com/pioneerspacesim/pioneer/issues/4691#issuecomment-540114463

--- src/scenegraph/Serializer.h.orig	2019-10-09 11:49:04 UTC
+++ src/scenegraph/Serializer.h
@@ -23,14 +23,14 @@
 // where possible, prefer serializing state information via JSON instead.
 namespace Serializer {
 	static_assert((sizeof(Uint32) == 4 && alignof(Uint32) == 4), "Int32 is sized differently on this platform and will not serialize properly.");
-	static_assert((sizeof(Uint64) == 8 && alignof(Uint64) == 8), "Int64 is sized differently on this platform and will not serialize properly.");
+	static_assert((sizeof(Uint64) == 8 && alignof(Uint64) <= 8), "Int64 is sized differently on this platform and will not serialize properly.");
 	static_assert((sizeof(Color) == 4 && alignof(Color) == 1), "Color is padded differently on this platform and will not serialize properly.");
 	static_assert((sizeof(vector2f) == 8 && alignof(vector2f) == 4), "Vector2f is padded differently on this platform and will not serialize properly.");
-	static_assert((sizeof(vector2d) == 16 && alignof(vector2d) == 8), "Vector2d is padded differently on this platform and will not serialize properly.");
+	static_assert((sizeof(vector2d) == 16 && alignof(vector2d) <= 8), "Vector2d is padded differently on this platform and will not serialize properly.");
 	static_assert((sizeof(vector3f) == 12 && alignof(vector3f) == 4), "Vector3f is padded differently on this platform and will not serialize properly.");
-	static_assert((sizeof(vector3d) == 24 && alignof(vector3d) == 8), "Vector3d is padded differently on this platform and will not serialize properly.");
+	static_assert((sizeof(vector3d) == 24 && alignof(vector3d) <= 8), "Vector3d is padded differently on this platform and will not serialize properly.");
 	static_assert((sizeof(Quaternionf) == 16 && alignof(Quaternionf) == 4), "Quaternionf is padded differently on this platform and will not serialize properly.");
-	static_assert((sizeof(Aabb) == 56 && alignof(Aabb) == 8), "Aabb is padded differently on this platform and will not serialize properly.");
+	static_assert((sizeof(Aabb) == 56 && alignof(Aabb) <= 8), "Aabb is padded differently on this platform and will not serialize properly.");
 
 	class Writer {
 	public:
