--- src/world_gui_manager.cpp.orig	2015-03-24 17:13:41 UTC
+++ src/world_gui_manager.cpp
@@ -273,7 +273,7 @@ WorldGUIManager::draw_overlay ()
   graphic_context->draw_string (410, bottom_line, "Zoom: ");
   graphic_context->draw_string (480, bottom_line, to_string(WorldViewComponent::instance()->get_zoom()));
 
-  graphic_context->draw_string (610, bottom_line, "..:: Construo V"VERSION" ::..");
+  graphic_context->draw_string (610, bottom_line, "..:: Construo V" VERSION " ::..");
   //graphic_context->draw_string (680, bottom_line, to_string(WorldViewComponent::instance()->get_zoom()));
 }
 
