From 7554822dd0b52d33ec7898e81b59e97164b00142 Mon Sep 17 00:00:00 2001
From: Uli Schlachter <psychon@znc.in>
Date: Sat, 21 Apr 2018 09:37:06 +0200
Subject: [PATCH] Fix assertion failure in the freetype backend

Fonts are kept in a hash table, so when creating a new font, the code
first checks the hash table for an already-existing entry and only then
is a new instance really created. There is an assert that checks that
the key used for the hash table lookup is the same as the instance that
is created later has, because otherwise the hash table was checked
incorrectly.

This assert failed in some conditions.

Fix this by fixing some places that initialised ft hash keys in a wrong
way.

Patch by Behdad Esfahbod and submitted via bugzilla.

Source: https://bugs.freedesktop.org/show_bug.cgi?id=105746#c4
Fixes: https://bugs.freedesktop.org/show_bug.cgi?id=105746
Signed-off-by: Uli Schlachter <psychon@znc.in>
---
 src/cairo-ft-font.c | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git a/src/cairo-ft-font.c b/src/cairo-ft-font.c
index 79aef78f5b0d..9b10708988d7 100644
--- src/cairo-ft-font.c
+++ src/cairo-ft-font.c
@@ -445,7 +445,7 @@ _cairo_ft_unscaled_font_init (cairo_ft_unscaled_font_t *unscaled,
 
     if (from_face) {
 	unscaled->from_face = TRUE;
-	_cairo_ft_unscaled_font_init_key (unscaled, TRUE, NULL, face->face_index, face);
+	_cairo_ft_unscaled_font_init_key (unscaled, TRUE, NULL, id, face);
 
 
         unscaled->have_color = FT_HAS_COLOR (face) != 0;
@@ -640,7 +640,7 @@ static cairo_status_t
 _cairo_ft_unscaled_font_create_from_face (FT_Face face,
 					  cairo_ft_unscaled_font_t **out)
 {
-    return _cairo_ft_unscaled_font_create_internal (TRUE, NULL, 0, face, out);
+    return _cairo_ft_unscaled_font_create_internal (TRUE, NULL, face->face_index, face, out);
 }
 
 static cairo_bool_t
-- 
2.17.0

