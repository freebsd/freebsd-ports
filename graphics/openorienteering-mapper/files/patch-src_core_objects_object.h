--- src/core/objects/object.h.orig	2020-03-14 12:50:26 UTC
+++ src/core/objects/object.h
@@ -1276,7 +1276,7 @@ float ObjectPathCoord::findClosestPointTo(const MapCoo
 inline
 constexpr ObjectPathCoord::operator bool() const
 {
-	return bool { object };
+	return static_cast<bool>(object);
 }
 
 }  // namespace OpenOrienteering
