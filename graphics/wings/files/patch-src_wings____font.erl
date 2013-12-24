
$FreeBSD$

--- src/wings__font.erl.orig
+++ src/wings__font.erl
@@ -11,45 +11,50 @@
 %%     $Id$
 %%
 
--module(wings__font, [Key,Desc,Width,Height,GlyphTab,Bitmaps]).
--export([key/0,desc/0,width/0,height/0,draw/1,char/1,char_width/1,
-	bold_char/1,bold_char_width/1]).
+-module(wings__font).
+-export([new/6,key/1,desc/1,width/1,height/1,draw/2,char/2,char_width/2,
+	bold_char/2,bold_char_width/2]).
 
-draw([C|T]) ->
-    char(C),
-    draw(T);
-draw([]) -> ok.
+-record(font, {key, desc, width, height, glyph_tab, bitmaps}).
 
-key() -> Key.
-desc() -> Desc.
+new(Key, Desc, Width, Height, GlyphTab, Bitmaps) ->
+    #font{key = Key, desc = Desc, width = Width, height = Height, glyph_tab = GlyphTab, bitmaps = Bitmaps}.
 
-char_width(C) ->
-    element(1, glyph_info(C)).
-width() ->
+draw(Font, [C|T]) ->
+    char(Font, C),
+    draw(Font, T);
+draw(_Font, []) -> ok.
+
+key(#font{key = Key}) -> Key.
+desc(#font{desc = Desc}) -> Desc.
+
+char_width(Font, C) ->
+    element(1, glyph_info(Font, C)).
+width(#font{width = Width}) ->
     insert_glyph(char_width, Width),
     Width.
-height() ->
+height(#font{height = Height}) ->
     insert_glyph(char_height, Height),
     Height.
 
-bold_char(C) ->
-    Glyph = glyph_info(C),
+bold_char(Font, C) ->
+    Glyph = glyph_info(Font, C),
     draw_glyph(Glyph),
     Cw = glyph_width(Glyph),
     gl:bitmap(1, 1, 0, 0, -Cw+1, 0, <<0>>),
     draw_glyph(Glyph).
 
-bold_char_width(C) ->
-    Glyph = glyph_info(C),
+bold_char_width(Font, C) ->
+    Glyph = glyph_info(Font, C),
     glyph_width(Glyph)+1.
 
-char(C) ->
-    draw_glyph(glyph_info(C)).
+char(Font, C) ->
+    draw_glyph(glyph_info(Font, C)).
 
 draw_glyph({W,H,Xorig,Yorig,Xmove,B}) ->
     gl:bitmap(W, H, Xorig, Yorig, Xmove, 0, B).
 
-glyph_info(C) ->
+glyph_info(#font{glyph_tab = GlyphTab, width = Width, height = Height, bitmaps = Bitmaps}, C) ->
     BitMap = case ets:lookup(GlyphTab, C) of
 	[] when is_integer(C), C > 0 ->
 	    %% Undefined character. Return a filled box.
