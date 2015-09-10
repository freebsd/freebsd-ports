--- src/wings_sel.erl.orig	2015-06-24 22:25:49 UTC
+++ src/wings_sel.erl
@@ -122,7 +122,7 @@ mapfold_1(_F, Acc, [], Shs, _St, ShsAcc)
 -type filter_fun() :: fun((visible_face_num() | edge_num() | vertex_num() | 0,
 			   #we{}) -> boolean()).
 -spec make(filter_fun(), sel_mode(), #st{}) ->
-    #st{sel::[{non_neg_integer(),gb_set()}]}.
+    #st{sel::[{non_neg_integer(),gb_sets:set()}]}.
 
 make(Filter, Mode, #st{shapes=Shapes}=St) when is_function(Filter, 2) ->
     Sel0 = gb_trees:values(Shapes),
