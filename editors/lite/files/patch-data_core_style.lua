--- data/core/style.lua.orig	2021-01-09 16:02:57 UTC
+++ data/core/style.lua
@@ -7,10 +7,10 @@ style.tab_width = common.round(170 * SCALE)
 style.caret_width = common.round(2 * SCALE)
 style.tab_width = common.round(170 * SCALE)
 
-style.font = renderer.font.load(EXEDIR .. "/data/fonts/font.ttf", 14 * SCALE)
-style.big_font = renderer.font.load(EXEDIR .. "/data/fonts/font.ttf", 34 * SCALE)
-style.icon_font = renderer.font.load(EXEDIR .. "/data/fonts/icons.ttf", 14 * SCALE)
-style.code_font = renderer.font.load(EXEDIR .. "/data/fonts/monospace.ttf", 13.5 * SCALE)
+style.font = renderer.font.load(DATADIR .. "/fonts/font.ttf", 14 * SCALE)
+style.big_font = renderer.font.load(DATADIR .. "/fonts/font.ttf", 34 * SCALE)
+style.icon_font = renderer.font.load(DATADIR .. "/fonts/icons.ttf", 14 * SCALE)
+style.code_font = renderer.font.load(DATADIR .. "/fonts/monospace.ttf", 13.5 * SCALE)
 
 style.background = { common.color "#2e2e32" }
 style.background2 = { common.color "#252529" }
