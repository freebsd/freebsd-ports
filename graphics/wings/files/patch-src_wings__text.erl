
$FreeBSD$

--- src/wings_text.erl.orig
+++ src/wings_text.erl
@@ -65,7 +65,7 @@
 
 bold_string_width([C|S], W) ->
     BCW = case wings_font_table:bold_char_width(C) of
-        undefined -> (current_font()):bold_char_width(C);
+        undefined -> wings__font:bold_char_width(current_font(), C);
         Other -> Other
     end,
     bold_string_width(S, BCW+W);
@@ -74,19 +74,19 @@
 
 char_width(C) ->
     case wings_font_table:char_width(C) of
-        undefined -> (current_font()):char_width(C);
+        undefined -> wings__font:char_width(current_font(), C);
         Other -> Other
     end.
 
 width() ->
     case wings_font_table:char(char_width) of
-        undefined -> (current_font()):width();
+        undefined -> wings__font:width(current_font());
         Other -> Other
     end.
 
 height() ->
     case wings_font_table:char(char_height) of
-        undefined -> (current_font()):height();
+        undefined -> wings__font:height(current_font());
         Other -> Other
     end.
 
@@ -111,13 +111,13 @@
 char(C) when is_atom(C) -> special(C);
 char(C) ->
     case wings_font_table:char(C) of
-        undefined -> (current_font()):char(C);
+        undefined -> wings__font:char(current_font(), C);
         Other -> Other
     end.
 
 bold([C|S]) ->
     case wings_font_table:bold_char(C) of
-        undefined -> (current_font()):bold_char(C);
+        undefined -> wings__font:bold_char(current_font(), C);
         Other -> Other
     end,
     bold(S);
@@ -195,7 +195,7 @@
     CharWidth = wings_text:width([$\s])*2,
     Line = [$\s,$\s|Line0],
     string_to_text_box(Tb#tb{text=Text,lw=LW+CharWidth,line=Line});
-    
+
 string_to_text_box(#tb{text=[{Style,String}=Stylized|Text],lw=Lw, max=Max, line=Line0,res=Res}=Tb0) ->
     Sw = width([Stylized]),
     NLW = Lw + Sw,
@@ -504,8 +504,8 @@
     {ok,Bin} = file:read_file(FontDir),
     Font = binary_to_term(Bin),
     Mod = load_font_1(Font),
-    Key = Mod:key(),
-    Desc = Mod:desc(),
+    Key = wings__font:key(Mod),
+    Desc = wings__font:desc(Mod),
     ets:insert(wings_fonts, {Key,Mod,Desc}).
 
 load_font_1({wings_font,?wings_version,Font}) ->
