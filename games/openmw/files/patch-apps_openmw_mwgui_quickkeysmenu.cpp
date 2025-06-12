--- apps/openmw/mwgui/quickkeysmenu.cpp.orig	2023-08-08 09:23:20 UTC
+++ apps/openmw/mwgui/quickkeysmenu.cpp
@@ -534,7 +534,7 @@ namespace MWGui
                     break;
                 }
                 case Type_Magic:
-                    std::string spellId = button->getUserString("Spell");
+                    std::string spellId{button->getUserString("Spell")};
                     key.mId = spellId;
                     break;
             }
