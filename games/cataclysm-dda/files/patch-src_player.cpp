--- src/player.cpp.orig	2015-03-09 05:25:34 UTC
+++ src/player.cpp
@@ -9788,7 +9788,7 @@ void player::pick_style() // Style selec
 
     uimenu kmenu;
     kmenu.text = _("Select a style (press ? for style info)");
-    std::auto_ptr<ma_style_callback> ma_style_info(new ma_style_callback());
+    std::unique_ptr<ma_style_callback> ma_style_info(new ma_style_callback());
     kmenu.callback = ma_style_info.get();
     kmenu.addentry( 0, true, 'c', _("Cancel") );
     if (keep_hands_free) {
