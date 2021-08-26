Backport fix from c8d5296f7bef162311a303ff904577b4010c5e80

--- src/Navaids/PositionedOctree.cxx.orig	2021-08-23 13:26:31 UTC
+++ src/Navaids/PositionedOctree.cxx
@@ -148,7 +148,7 @@ void Leaf::visit(const SGVec3d& aPos, double aCutoff,
 
 void Leaf::insertChild(FGPositioned::Type ty, PositionedID id)
 {
-  assert(childrenLoaded);
+  assert(_childrenLoaded);
   children.insert(children.end(), TypedPositioned(ty, id));
 }
 
