--- scene/gui/rich_text_label.cpp.orig	2018-01-10 13:20:47 UTC
+++ scene/gui/rich_text_label.cpp
@@ -806,9 +806,9 @@ void RichTextLabel::_gui_input(Ref<Input
 							// Erase previous selection.
 							if (selection.active) {
 								selection.from = NULL;
-								selection.from_char = NULL;
+								selection.from_char = 0;
 								selection.to = NULL;
-								selection.to_char = NULL;
+								selection.to_char = 0;
 								selection.active = false;
 
 								update();
