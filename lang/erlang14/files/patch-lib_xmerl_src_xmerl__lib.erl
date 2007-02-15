
$FreeBSD$

--- lib/xmerl/src/xmerl_lib.erl.orig
+++ lib/xmerl/src/xmerl_lib.erl
@@ -218,13 +218,11 @@
 
 expand_content([{H} | T], Pos, Parents, Norm) ->
     expand_content(H ++ T, Pos, Parents, Norm);
-expand_content([H | T], Pos, Parents, Norm) when is_tuple(H) ->
+expand_content([H | T], Pos, Parents, Norm) ->
     [expand_element(H, Pos, Parents, Norm)
      | expand_content(T, Pos+1, Parents, Norm)];
 expand_content([], _Pos, _Parents, _Norm) ->
-    [];
-expand_content(Content,Pos,Parents,Norm) ->
-    [expand_element(Content, Pos, Parents, Norm)].
+    [].
 
 expand_attributes(Attrs) ->
     expand_attributes(Attrs, 1, []).
