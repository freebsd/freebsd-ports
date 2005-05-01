
$FreeBSD$

--- lib/compiler/src/beam_validator.erl.orig
+++ lib/compiler/src/beam_validator.erl
@@ -415,7 +415,7 @@
     TupleType0 = get_term_type(Tuple, Vst0),
     PosType = get_term_type(Pos, Vst0),
     Vst1 = branch_state(Fail, Vst0),
-    TupleType = upgrade_type({tuple,[get_tuple_size(PosType)]}, TupleType0),
+    TupleType = upgrade_tuple_type({tuple,[get_tuple_size(PosType)]}, TupleType0),
     Vst = set_type(TupleType, Tuple, Vst1),
     set_type_reg(term, Dst, Vst);
 valfun_4({arithbif,Op,F,Src,Dst}, Vst) ->
@@ -529,8 +529,9 @@
     assert_term(Float, Vst),
     set_type({float,[]}, Float, branch_state(Lbl, Vst));
 valfun_4({test,is_tuple,{f,Lbl},[Tuple]}, Vst) ->
-    assert_term(Tuple, Vst),
-    set_type({tuple,[0]}, Tuple, branch_state(Lbl, Vst));
+    Type0 = get_term_type(Tuple, Vst),
+    Type = upgrade_tuple_type({tuple,[0]}, Type0),
+    set_type(Type, Tuple, branch_state(Lbl, Vst));
 valfun_4({test,is_nonempty_list,{f,Lbl},[Cons]}, Vst) ->
     assert_term(Cons, Vst),
     set_type(cons, Cons, branch_state(Lbl, Vst));
@@ -843,54 +844,25 @@
 assert_type(Needed, Actual) ->
     error({bad_type,{needed,Needed},{actual,Actual}}).
 
-%% upgrade_type/2 is used when linear code finds out more and
-%% more information about a type, so the type gets "narrower"
-%% or perhaps inconsistent. In the case of inconsistency
-%% we mostly widen the type to 'term' to make subsequent
-%% code fail if it assumes anything about the type.
 
-upgrade_type(Same, Same) -> Same;
-upgrade_type(term, OldT) -> OldT;
-upgrade_type(NewT, term) -> NewT;
-upgrade_type({Type,New}=NewT, {Type,Old}=OldT)
-  when Type == atom; Type == integer; Type == float ->
-    if New =:= Old -> OldT;
-       New =:= [] -> OldT;
-       Old =:= [] -> NewT;
-       true -> term
-    end;
-upgrade_type({Type,_}=NewT, number) 
-  when Type == integer; Type == float ->
-    NewT;
-upgrade_type(number, {Type,_}=OldT) 
-  when Type == integer; Type == float ->
-    OldT;
-upgrade_type(bool, {atom,A}) ->
-    upgrade_bool(A);
-upgrade_type({atom,A}, bool) ->
-    upgrade_bool(A);
-upgrade_type({tuple,[Sz]}, {tuple,[OldSz]})
-  when is_integer(Sz) ->
-    {tuple,[max(Sz, OldSz)]};
-upgrade_type({tuple,Sz}=T, {tuple,[_]}) 
-  when is_integer(Sz) ->
-    %% This also takes care of the user error when a tuple element
-    %% is accesed outside the known exact tuple size; there is 
-    %% no more type information, just a runtime error which is not
-    %% our problem.
-    T;
-upgrade_type({tuple,[Sz]}, {tuple,_}=T) 
-  when is_integer(Sz) ->
-    %% Same as the previous clause but mirrored.
-    T;
-upgrade_type(_A, _B) ->
-    %%io:format("upgrade_type: ~p ~p\n", [_A,_B]),
-    term.
+%% upgrade_tuple_type(NewTupleType, OldType) -> TupleType.
+%%  upgrade_tuple_type/2 is used when linear code finds out more and
+%%  more information about a tuple type, so that the type gets more
+%%  specialized. If OldType is not a tuple type, the type information
+%%  is inconsistent, and we know that some instructions will never
+%%  be executed at run-time.
 
-upgrade_bool([]) -> bool;
-upgrade_bool(true) -> {atom,true};
-upgrade_bool(false) -> {atom,false};
-upgrade_bool(_) -> term.
+upgrade_tuple_type({tuple,[Sz]}, {tuple,[OldSz]}=T) when Sz < OldSz ->
+    %% The old type has a higher value for the least tuple size.
+    T;
+upgrade_tuple_type({tuple,_}=T, _) ->
+    %% The new type information is exact or has a higher value for
+    %% the least tuple size.
+    %%     Note that inconsistencies are also handled in this
+    %% clause, e.g. if the old type was an integer or a tuple accessed
+    %% outside its size; inconsistences will generally cause an exception
+    %% at run-time but are safe from our point of view.
+    T.
 
 get_tuple_size({integer,[]}) -> 0;
 get_tuple_size({integer,Sz}) -> Sz;
@@ -1172,7 +1144,7 @@
 	end,
     case get_term_type({x,0}, Vst) of
 	{integer,[]} -> TupleType;
-	{integer,I} -> upgrade_type({tuple,[I]}, TupleType);
+	{integer,I} -> upgrade_tuple_type({tuple,[I]}, TupleType);
 	_ -> TupleType
     end;
 return_type_1(erlang, F, A, _) ->
@@ -1214,9 +1186,6 @@
 
 min(A, B) when is_integer(A), is_integer(B), A < B -> A;
 min(A, B) when is_integer(A), is_integer(B) -> B.
-
-max(A, B) when is_integer(A), is_integer(B), A > B -> A;
-max(A, B) when is_integer(A), is_integer(B) -> B.
 
 gb_trees_from_list(L) -> gb_trees:from_orddict(orddict:from_list(L)).
 
