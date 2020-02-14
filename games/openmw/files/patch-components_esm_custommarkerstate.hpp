--- components/esm/custommarkerstate.hpp.orig	2019-03-10 10:50:29 UTC
+++ components/esm/custommarkerstate.hpp
@@ -16,7 +16,7 @@ struct CustomMarker
 
     std::string mNote;
 
-    bool operator == (const CustomMarker& other)
+    bool operator == (const CustomMarker& other) const
     {
         return mNote == other.mNote && mCell == other.mCell && mWorldX == other.mWorldX && mWorldY == other.mWorldY;
     }
