--- apps/openmw/mwgui/resourceskin.cpp.orig	2023-08-08 09:23:20 UTC
+++ apps/openmw/mwgui/resourceskin.cpp
@@ -9,11 +9,11 @@ namespace MWGui
     void resizeSkin(MyGUI::xml::ElementPtr _node)
     {
         _node->setAttribute("type", "ResourceSkin");
-        const std::string size = _node->findAttribute("size");
+        const auto size = _node->findAttribute("size");
         if (!size.empty())
             return;
 
-        const std::string textureName = _node->findAttribute("texture");
+        const std::string textureName{_node->findAttribute("texture")};
         if (textureName.empty())
             return;
 
@@ -30,11 +30,11 @@ namespace MWGui
             if (basis->getName() != "BasisSkin")
                 continue;
 
-            const std::string basisSkinType = basis->findAttribute("type");
+            const auto basisSkinType = basis->findAttribute("type");
             if (Misc::StringUtils::ciEqual(basisSkinType, "SimpleText"))
                 continue;
 
-            const std::string offset = basis->findAttribute("offset");
+            const auto offset = basis->findAttribute("offset");
             if (!offset.empty())
                 continue;
 
@@ -45,7 +45,7 @@ namespace MWGui
             {
                 if (state->getName() == "State")
                 {
-                    const std::string stateOffset = state->findAttribute("offset");
+                    const auto stateOffset = state->findAttribute("offset");
                     if (!stateOffset.empty())
                         continue;
 
@@ -56,7 +56,7 @@ namespace MWGui
                         bool hasTileSize = false;
                         while (property.next("Property"))
                         {
-                            const std::string key = property->findAttribute("key");
+                            const auto key = property->findAttribute("key");
                             if (key != "TileSize")
                                 continue;
 
