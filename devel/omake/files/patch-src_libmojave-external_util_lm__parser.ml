$NetBSD: patch-ax,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/libmojave-external/util/lm_parser.ml.orig	2007-01-25 18:31:18.000000000 +0000
+++ src/libmojave-external/util/lm_parser.ml
@@ -282,15 +282,11 @@ struct
       let debug = "ProdItem"
 
       let hash item =
-         let { prod_item_name   = name;
-               prod_item_left   = left;
-               prod_item_right  = right;
-               prod_item_action = action
-             } = item
-         in
+         let name = item.prod_item_name in
+         let action = item.prod_item_action in
          let hash = hash_combine (IVar.hash name) (IAction.hash action) in
-         let hash = ivar_list_hash hash left in
-         let hash = ivar_list_hash hash right in
+         let hash = ivar_list_hash hash item.prod_item_left in
+         let hash = ivar_list_hash hash item.prod_item_right in
             hash
 
       let compare item1 item2 =
@@ -657,18 +653,12 @@ struct
             fprintf buf "@ %a: %a" (pp_print_ivar info) v (pp_print_pda_action info) action) actions
 
    let pp_print_prod_item_core info buf item =
-      let { prod_item_action = action;
-            prod_item_name   = name;
-            prod_item_left   = left;
-            prod_item_right  = right
-          } = item
-      in
       let hash = info.info_hash in
          fprintf buf "%a ::=%a .%a (%a)" (**)
-            (pp_print_ivar hash) name
-            (pp_print_ivars hash) (List.rev left)
-            (pp_print_ivars hash) right
-            (pp_print_iaction hash) action
+            (pp_print_ivar hash) item.prod_item_name
+            (pp_print_ivars hash) (List.rev item.prod_item_left)
+            (pp_print_ivars hash) item.prod_item_right
+            (pp_print_iaction hash) item.prod_item_action
 
    let pp_print_prod_item info buf item =
       pp_print_prod_item_core info buf (ProdItem.get info.info_hash.hash_prod_item_state item)
@@ -678,40 +668,27 @@ struct
             fprintf buf "@ %a" (pp_print_prod_item info) item) items
 
    let pp_print_state info buf state =
-      let { info_state_items = items } = State.get info.info_hash.hash_state_state state in
+      let items = (State.get info.info_hash.hash_state_state state).info_state_items in
          eprintf "@[<v 3>State %d" (State.hash state);
          pp_print_prod_item_set info buf items;
          eprintf "@]"
 
    let pp_print_info_item info buf info_item =
-      let { info_hash = hash;
-            info_hash_state_item = hash_state_item
-          } = info
-      in
-      let { info_item_index = index;
-            info_item_entries = entries
-          } = info_item
-      in
-         fprintf buf "@[<v 3>State %d:" index;
+      let hash = info.info_hash in
+      let hash_state_item = info.info_hash_state_item in
+         fprintf buf "@[<v 3>State %d:" info_item.info_item_index;
          Array.iter (fun entry ->
-               let { prop_state_item = state_item;
-                     prop_vars = lookahead
-                   } = entry
-               in
+               let state_item = entry.prop_state_item in
+               let lookahead = entry.prop_vars in
                let _, prod_item = StateItem.get hash_state_item state_item in
-                  fprintf buf "@ @[<hv 3>%a@ @[<b 2>#%a@]@]" (pp_print_prod_item info) prod_item (pp_print_ivar_set hash) lookahead) entries;
+                  fprintf buf "@ @[<hv 3>%a@ @[<b 2>#%a@]@]" (pp_print_prod_item info) prod_item (pp_print_ivar_set hash) lookahead) info_item.info_item_entries;
          fprintf buf "@]"
 
    let pp_print_info buf info =
-      let { info_grammar = gram;
-            info_nullable = nullable;
-            info_first = first;
-            info_hash = hash
-          } = info
-      in
-         fprintf buf "@[<v 0>%a" pp_print_grammar gram;
-         fprintf buf "@ @[<b 3>Nullable:%a@]" (pp_print_ivar_set hash) nullable;
-         fprintf buf "@ @[<v 3>First:%a@]" (pp_print_ivar_table hash) first;
+      let hash = info.info_hash in
+         fprintf buf "@[<v 0>%a" pp_print_grammar info.info_grammar;
+         fprintf buf "@ @[<b 3>Nullable:%a@]" (pp_print_ivar_set hash) info.info_nullable;
+         fprintf buf "@ @[<v 3>First:%a@]" (pp_print_ivar_table hash) info.info_first;
          fprintf buf "@]"
 
    let pp_print_lookahead hash buf look =
@@ -917,16 +894,11 @@ struct
       let changed, prods =
          VarMTable.fold_all (fun (changed, prods) _ prodlist ->
                List.fold_left (fun (changed, prods) prod ->
-                     let { prod_action = action;
-                           prod_name   = name;
-                           prod_prec   = pre
-                         } = prod
-                     in
-                        if ActionSet.mem actions action then
-                           changed, prods
-                        else
-                           let prod = { prod with prod_prec = PrecTable.find prec_translate pre } in
-                              true, VarMTable.add prods name prod) (changed, prods) prodlist) (false, prod1) prod2
+                     if ActionSet.mem actions prod.prod_action then
+                        changed, prods
+                     else
+                        let prod = { prod with prod_prec = PrecTable.find prec_translate prod.prod_prec } in
+                           true, VarMTable.add prods prod.prod_name prod) (changed, prods) prodlist) (false, prod1) prod2
       in
 
       (* Union of the start symbols *)
@@ -1012,12 +984,10 @@ struct
       let step first prods =
          IVarTable.fold (fun (first, changed) _ prods ->
                List.fold_left (fun (first, changed) prod ->
-                     let { prod_item_name = x;
-                           prod_item_right = rhs
-                         } = ProdItem.get prod_state prod
-                     in
+                     let prod_item = ProdItem.get prod_state prod in
+                     let x = prod_item.prod_item_name in
                      let set = IVarTable.find first x in
-                     let set' = first_rhs nullable first set rhs in
+                     let set' = first_rhs nullable first set prod_item.prod_item_right in
                      let set, changed =
                         if changed || IVarSet.cardinal set' <> IVarSet.cardinal set then
                            set', true
@@ -1059,10 +1029,8 @@ struct
     * Get the set of first symbols that can begin a list.
     *)
    let lookahead info rhs =
-      let { info_first = first;
-            info_nullable = nullable
-          } = info
-      in
+      let first = info.info_first in
+      let nullable = info.info_nullable in
       let rec search set rhs =
          match rhs with
             v :: rhs ->
@@ -1274,14 +1242,10 @@ struct
       let hash = info.info_hash.hash_prod_item_state in
          ProdItemSet.fold (fun delta prod_item ->
                let core = ProdItem.get hash prod_item in
-               let { prod_item_left = left;
-                     prod_item_right = right
-                   } = core
-               in
-                  match right with
+                  match core.prod_item_right with
                      v :: right ->
                         let core =
-                           { core with prod_item_left = v :: left;
+                           { core with prod_item_left = v :: core.prod_item_left;
                                        prod_item_right = right
                            }
                         in
@@ -1517,11 +1481,7 @@ struct
       let goto_table = StateTable.find shift_table state in
       let prod_item_hash = info.info_hash.hash_prod_item_state in
       let prod_item_core = ProdItem.get prod_item_hash prod_item in
-      let { prod_item_left = left;
-            prod_item_right = right
-          } = prod_item_core
-      in
-         match right with
+         match prod_item_core.prod_item_right with
             v :: right ->
                (* If v is a nonterminal, then also propagate to initial items *)
                let prop_items =
@@ -1534,7 +1494,7 @@ struct
                (* Propagate directly to the next state *)
                let next_state = IVarTable.find goto_table v in
                let next_item_core =
-                  { prod_item_core with prod_item_left = v :: left;
+                  { prod_item_core with prod_item_left = v :: prod_item_core.prod_item_left;
                                         prod_item_right = right
                   }
                in
@@ -1833,8 +1793,8 @@ struct
                      item :: items ->
                         let core = ProdItem.get hash item in
                         let empty_flag =
-                           match core with
-                              { prod_item_left = []; prod_item_right = [] } ->
+                           match core.prod_item_left, core.prod_item_right with
+                              [], [] ->
                                  true
                             | _ ->
                                  false
@@ -1865,14 +1825,12 @@ struct
                      look)
 
    let reduce_actions info empties prop_table =
-      let { info_head_lookahead = look_table } = info in
+      let look_table = info.info_head_lookahead in
       let hash = info.info_hash.hash_prod_item_state in
       let hash_state_item = info.info_hash_state_item in
          Array.fold_left (fun actions entry ->
-               let { prop_state_item = state_item;
-                     prop_vars = look3
-                   } = entry
-               in
+               let state_item = entry.prop_state_item in
+               let look3 = entry.prop_vars in
                let state, item = StateItem.get hash_state_item state_item in
                let core = ProdItem.get hash item in
                   match core.prod_item_right with
@@ -1902,8 +1860,8 @@ struct
     * Error messages.
     *)
    let shift_reduce_conflict info state v shift_state reduce_item =
-      let { info_hash = hash } = info in
-      let { hash_prod_item_state = hash_prod_item } = hash in
+      let hash = info.info_hash in
+      let hash_prod_item = hash.hash_prod_item_state in
       let pp_print_ivar = pp_print_ivar hash in
       let pp_print_iaction = pp_print_iaction hash in
       let reduce_core = ProdItem.get hash_prod_item reduce_item in
@@ -1917,8 +1875,8 @@ struct
             raise (Invalid_argument "Lm_parser.shift_reduce_conflict\n\tset MP_DEBUG=parse_conflict_is_warning to ignore this error")
 
    let reduce_reduce_conflict info state v reduce_item action =
-      let { info_hash = hash } = info in
-      let { hash_prod_item_state = hash_prod_item } = hash in
+      let hash = info.info_hash in
+      let hash_prod_item = hash.hash_prod_item_state in
       let pp_print_ivar = pp_print_ivar hash in
       let pp_print_iaction = pp_print_iaction hash in
       let reduce_core = ProdItem.get hash_prod_item reduce_item in
@@ -1936,24 +1894,18 @@ struct
     * This is finally the stage where we check for conflicts.
     *)
    let process_reduce_actions info reduce_actions action_table =
-      let { info_grammar         = gram;
-            info_prec            = var_prec_table;
-            info_hash = { hash_prod_item_state = hash_prod_item }
-          } = info
-      in
-      let { gram_prec_table = prec_table } = gram in
+      let gram = info.info_grammar in
+      let var_prec_table = info.info_prec in
+      let hash_prod_item = info.info_hash.hash_prod_item_state in
+      let prec_table = gram.gram_prec_table in
       let state_item_hash = info.info_hash_state_item in
          StateItemTable.fold (fun action_table state_item look ->
                let look = lookahead_set look in
                let state, item = StateItem.get state_item_hash state_item in
-               let { prod_item_name   = name;
-                     prod_item_action = action;
-                     prod_item_left   = left;
-                     prod_item_prec   = prec_name
-                   } = ProdItem.get hash_prod_item item
-               in
+               let prod_item = ProdItem.get hash_prod_item item in
+               let prec_name = prod_item.prod_item_prec in
                let assoc = Precedence.assoc prec_table prec_name in
-               let reduce = ReduceAction (action, name, List.length left) in
+               let reduce = ReduceAction (prod_item.prod_item_action, prod_item.prod_item_name, List.length prod_item.prod_item_left) in
                let actions = StateTable.find action_table state in
                let actions =
                   IVarSet.fold (fun actions v ->
@@ -2006,7 +1958,8 @@ struct
                { prod_item_right = [];
                  prod_item_action = action;
                  prod_item_name = name;
-                 prod_item_left = left
+                 prod_item_left = left;
+                 prod_item_prec = _
                } ->
                   let state_item = StateItem.create info.info_hash_state_item (state, item) in
                   let lookahead = prop_table.(StateItem.hash state_item).prop_vars in
@@ -2027,18 +1980,14 @@ struct
     * Flatten a production state to a pda description.
     *)
    let pda_info_of_items info prop_table state items =
-      let { info_first = first;
-            info_hash_state_item = hash_state_item;
-            info_hash = { hash_prod_item_state = hash_prod_item }
-          } = info
-      in
+      let first = info.info_first in
+      let hash_state_item = info.info_hash_state_item in
+      let hash_prod_item = info.info_hash.hash_prod_item_state in
       let items, next =
          ProdItemSet.fold (fun (items, next) prod_item ->
                let core = ProdItem.get hash_prod_item prod_item in
-               let { prod_item_left  = left;
-                     prod_item_right = right
-                   } = core
-               in
+               let left = core.prod_item_left in
+               let right = core.prod_item_right in
                let item =
                   { pda_item_left  = left;
                     pda_item_right = right
@@ -2094,7 +2043,7 @@ struct
       (* Build the PDA states *)
       let table =
          State.map_array (fun state core ->
-               let { info_state_items = items } = core in
+               let items = core.info_state_items in
                   { pda_delta  = pda_delta (StateTable.find trans_table state);
                     pda_reduce = reduce_early info prop_table state items;
                     pda_info   = pda_info_of_items info prop_table state items
@@ -2155,7 +2104,7 @@ struct
     * Exceptions.
     *)
    let parse_error loc hash run _stack state (v : ivar) =
-      let { pda_info = { pda_items = items; pda_next = next } } = run.run_states.(state) in
+      let { pda_items = items; pda_next = next } = run.run_states.(state).pda_info in
       let pp_print_ivar = pp_print_ivar hash in
       let buf = stdstr in
          fprintf buf "@[<v 0>Syntax error on token %a" pp_print_ivar v;
@@ -2188,7 +2137,7 @@ struct
 
    let pda_loop hash run arg start =
       let rec pda_lookahead arg stack state tok =
-         let { pda_delta = delta } = run.run_states.(state) in
+         let delta = run.run_states.(state).pda_delta in
          let v, loc, x = tok in
             match
                (try IVarTable.find delta v with
@@ -2323,24 +2272,24 @@ struct
    let prec_max = Precedence.prec_max
 
    let add_assoc info pre assoc =
-      let { parse_grammar = gram } = info in
-      let { gram_prec_table = prec_table } = gram in
+      let gram = info.parse_grammar in
+      let prec_table = gram.gram_prec_table in
       let prec_table = Precedence.add_assoc prec_table pre assoc in
       let gram = { gram with gram_prec_table = prec_table } in
       let info = { parse_grammar = gram; parse_pda = None } in
          info
 
    let create_prec_lt info pre assoc =
-      let { parse_grammar = gram } = info in
-      let { gram_prec_table = prec_table } = gram in
+      let gram = info.parse_grammar in
+      let prec_table = gram.gram_prec_table in
       let prec_table, pre = Precedence.create_prec_lt prec_table pre assoc in
       let gram = { gram with gram_prec_table = prec_table } in
       let info = { parse_grammar = gram; parse_pda = None } in
          info, pre
 
    let create_prec_gt info pre assoc =
-      let { parse_grammar = gram } = info in
-      let { gram_prec_table = prec_table } = gram in
+      let gram = info.parse_grammar in
+      let prec_table = gram.gram_prec_table in
       let prec_table, pre = Precedence.create_prec_gt prec_table pre assoc in
       let gram = { gram with gram_prec_table = prec_table } in
       let info = { parse_grammar = gram; parse_pda = None } in
