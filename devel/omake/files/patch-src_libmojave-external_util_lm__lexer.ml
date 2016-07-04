$NetBSD: patch-aw,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/libmojave-external/util/lm_lexer.ml.orig	2007-01-25 18:31:18.000000000 +0000
+++ src/libmojave-external/util/lm_lexer.ml
@@ -1325,10 +1325,8 @@ struct
     * Expressions.
     *)
    let pp_print_exp buf exp =
-      let { exp_clauses = clauses;
-            exp_id = id
-          } = exp
-      in
+      let clauses = exp.exp_clauses in
+      let id = exp.exp_id in
          fprintf buf "Id: %d" id;
          List.iter (fun (action, id, regex) ->
                fprintf buf "@ @[<hv 3>Clause:@ id = %d@ action = %a@ @[<hv 3>regex =@ %a@]@]" (**)
@@ -1370,10 +1368,8 @@ struct
    let add_clause_exp exp action s =
       let regex = regex_of_string s in
       let arity = regex_arg_count 0 regex in
-      let { exp_clauses = clauses;
-            exp_id      = id
-          } = exp
-      in
+      let clauses = exp.exp_clauses in
+      let id = exp.exp_id in
       let exp =
          { exp_clauses = (action, id, regex) :: clauses;
            exp_id      = succ id
@@ -1395,11 +1391,9 @@ struct
     * Take the union of two expression lists.
     *)
    let union_exp exp1 exp2 =
-      let { exp_clauses = clauses1;
-            exp_id = id1
-          } = exp1
-      in
-      let { exp_clauses = clauses2 } = exp2 in
+      let clauses1 = exp1.exp_clauses in
+      let id1 = exp1.exp_id in
+      let clauses2 = exp2.exp_clauses in
       let actions =
          List.fold_left (fun actions (action, _, _) ->
                ActionSet.add actions action) ActionSet.empty clauses1
@@ -1474,20 +1468,16 @@ struct
                counter min final max start
 
    let pp_print_nfa_state buf nfa_state =
-      let { nfa_state_index = index;
-            nfa_state_action = action
-          } = nfa_state
-      in
+      let index = nfa_state.nfa_state_index in
+      let action = nfa_state.nfa_state_action in
          fprintf buf "@[<hv 3>NFA state %d:@ action %a@]" index pp_print_nfa_action action
 
    let pp_print_nfa buf nfa =
-      let { nfa_hash  = hash;
-            nfa_start = start;
-            nfa_search_start = search;
-            nfa_search_states = search_states;
-            nfa_table = table
-          } = nfa
-      in
+      let hash = nfa.nfa_hash in
+      let start = nfa.nfa_start in
+      let search = nfa.nfa_search_start in
+      let search_states = nfa.nfa_search_states in
+      let table = nfa.nfa_table in
          fprintf buf "@[<hv 3>NFA:@ start = %a@ search = %a@ @[<b 3>search-states =%a@]" (**)
             (pp_print_nfa_id hash) start
             (pp_print_nfa_id hash) search
@@ -1500,7 +1490,7 @@ struct
     * Construct a new state.
     *)
    let nfa_state accum action =
-      let { nfa_index = index } = accum in
+      let index = accum.nfa_index in
       let state =
          { nfa_state_index = index;
            nfa_state_action = action
@@ -1582,7 +1572,7 @@ struct
             in
                accum, info, start, start1 :: final1 :: states
        | RegexInterval (regex, min, max) ->
-            let { nfa_counter = counter } = accum in
+            let counter = accum.nfa_counter in
             let accum, start1 = nfa_state accum NfaActionNone in
             let accum, final1 =
                nfa_state accum (NfaActionIncrCounter (counter, min, final.nfa_state_index, max, start1.nfa_state_index))
@@ -1605,11 +1595,11 @@ struct
 
          (* Arguments *)
        | RegexArg regex ->
-            let { nfa_arg_index = argindex } = accum in
+            let argindex = accum.nfa_arg_index in
             let accum, final1 = nfa_state accum (NfaActionArgStop (argindex, final.nfa_state_index)) in
             let accum, start1 = nfa_state accum NfaActionNone in
             let start = set_action start (NfaActionArgStart (argindex, start1.nfa_state_index)) in
-            let { nfa_arg_number = argnumber } = info in
+            let argnumber = info.nfa_arg_number in
             let accum = { accum with nfa_arg_index = succ argindex } in
             let info = { info with nfa_arg_number  = succ argnumber } in
             let accum, info, start1, states =
@@ -1783,10 +1773,8 @@ struct
                fprintf buf "search-stop at %d" off
 
    let pp_print_dfa_actions nfa_hash buf action =
-      let { dfa_action_final = final;
-            dfa_action_actions = actions
-          } = action
-      in
+      let final = action.dfa_action_final in
+      let actions = action.dfa_action_actions in
       let () =
          fprintf buf "@[<hv 3>(action"
       in
@@ -1798,20 +1786,16 @@ struct
                ()
       in
          NfaStateTable.iter (fun dst action ->
-               let { dfa_action_src = src;
-                     dfa_action_args = args
-                   } = action
-               in
+               let src = action.dfa_action_src in
+               let args = action.dfa_action_args in
                   fprintf buf "@ @[<hv 3>(%a -> %a" (pp_print_nfa_id nfa_hash) src (pp_print_nfa_id nfa_hash) dst;
                   List.iter (fun action -> fprintf buf "@ %a" pp_print_dfa_arg_action action) args;
                   fprintf buf ")@]") actions;
          fprintf buf ")@]"
 
    let pp_print_pre_actions buf action =
-      let { pre_action_final = final;
-            pre_action_args = args
-          } = action
-      in
+      let final = action.pre_action_final in
+      let args = action.pre_action_args in
       let () =
          fprintf buf "@[<hv 3>(pre-action@ "
       in
@@ -1897,10 +1881,10 @@ struct
     * DFA actions.
     *)
    let dfa_action_is_empty action =
-      match action with
-         { dfa_action_final = None; dfa_action_actions = actions } ->
-            NfaStateTable.is_empty actions
-       | { dfa_action_final = Some _ } ->
+      match action.dfa_action_final with
+         None ->
+            NfaStateTable.is_empty action.dfa_action_actions
+       | Some _ ->
             false
 
    (*
@@ -1920,21 +1904,15 @@ struct
                ArgTable.add args ArgSearch pos
 
    let dfa_eval_action dfa info action =
-      let { dfa_channel = channel;
-            dfa_args = args_table
-          } = info
-      in
-      let { dfa_action_final = final;
-            dfa_action_actions = actions
-          } = action
-      in
+      let channel = info.dfa_channel in
+      let args_table = info.dfa_args in
+      let final = action.dfa_action_final in
+      let actions = action.dfa_action_actions in
       let pos = Input.lex_pos channel in
       let args_table =
          NfaStateTable.map (fun action ->
-               let { dfa_action_src = src;
-                     dfa_action_args = actions
-                   } = action
-               in
+               let src = action.dfa_action_src in
+               let actions = action.dfa_action_args in
                let args =
                   try NfaStateTable.find args_table src with
                      Not_found ->
@@ -2140,10 +2118,8 @@ struct
     * the DFA state.
     *)
    let close_state dfa table nids c =
-      let { dfa_search_states = search_states;
-            dfa_nfa_hash = nfa_hash
-          } = dfa
-      in
+      let search_states = dfa.dfa_search_states in
+      let nfa_hash = dfa.dfa_nfa_hash in
       let final, actions =
          List.fold_left (fun final_actions nid ->
                let frontier =
@@ -2152,10 +2128,8 @@ struct
                   if !debug_lexgen then
                      eprintf "@[<v 3>Frontier:@ %a@]@." (pp_print_frontier nfa_hash) frontier;
                   NfaStateTable.fold (fun (final', actions) id action ->
-                        let { pre_action_final = final;
-                              pre_action_args = args
-                            } = action
-                        in
+                        let final = action.pre_action_final in
+                        let args = action.pre_action_args in
                         let final =
                            match final', final with
                               Some (clause_id', _nid'), Some clause_id ->
@@ -2264,11 +2238,9 @@ struct
          extend_args ("" :: args) (succ len1) len2
 
    let dfa_args dfa_info lexeme =
-      let { dfa_start_pos = start;
-            dfa_stop_pos = stop;
-            dfa_stop_args = args
-          } = dfa_info
-      in
+      let start = dfa_info.dfa_start_pos in
+      let stop = dfa_info.dfa_stop_pos in
+      let args = dfa_info.dfa_stop_args in
 
       (* Get the pairs of argument info *)
       let info, start_pos =
@@ -2326,11 +2298,9 @@ struct
     * Add a state to the DFA.  It is initially empty.
     *)
    let dfa_find_state dfa nids =
-      let { dfa_map    = map;
-            dfa_length = dfa_id;
-            dfa_states = states
-          } = dfa
-      in
+      let map = dfa.dfa_map in
+      let dfa_id = dfa.dfa_length in
+      let states = dfa.dfa_states in
          try DfaStateTable.find map nids with
             Not_found ->
                (* Make a new state *)
@@ -2362,14 +2332,10 @@ struct
     * an entry in the transition table yet.
     *)
    let create_entry dfa dfa_state c =
-      let { dfa_dfa_hash = dfa_hash;
-            dfa_table = table
-          } = dfa
-      in
-      let { dfa_state_set = nids;
-            dfa_state_delta = delta
-          } = dfa_state
-      in
+      let dfa_hash = dfa.dfa_dfa_hash in
+      let table = dfa.dfa_table in
+      let nids = dfa_state.dfa_state_set in
+      let delta = dfa_state.dfa_state_delta in
       let frontier, actions = close_next_state dfa table (DfaState.get dfa_hash nids) c in
          if frontier = [] && dfa_action_is_empty actions then
             dfa_state.dfa_state_delta <- TransTable.add delta c DfaNoTransition
@@ -2437,10 +2403,8 @@ struct
       let () = loop dfa_state c in
 
       (* Now figure out what happened *)
-      let { dfa_stop_clause = clause;
-            dfa_stop_pos    = stop;
-          } = dfa_info
-      in
+      let clause = dfa_info.dfa_stop_clause in
+      let stop = dfa_info.dfa_stop_pos in
          (*
           * If we did not get a match, return the channel to
           * the starting position, and raise an exception.
@@ -2489,10 +2453,8 @@ struct
       let () = loop dfa_state c in
 
       (* Now figure out what happened *)
-      let { dfa_stop_clause = clause;
-            dfa_stop_pos    = stop;
-          } = dfa_info
-      in
+      let clause = dfa_info.dfa_stop_clause in
+      let stop = dfa_info.dfa_stop_pos in
          (*
           * If we did not get a match, return the channel to
           * the starting position, and raise an exception.
@@ -2551,10 +2513,8 @@ struct
       let () = loop dfa_state c in
 
       (* Now figure out what happened *)
-      let { dfa_stop_clause = clause;
-            dfa_stop_pos    = stop;
-          } = dfa_info
-      in
+      let clause = dfa_info.dfa_stop_clause in
+      let stop = dfa_info.dfa_stop_pos in
          (*
           * If we did not get a match, return all the text to
           * the end of the channel.
@@ -2610,14 +2570,12 @@ struct
          if !debug_lexgen || !debug_lex then
             eprintf "%a@." pp_print_nfa nfa
       in
-      let { nfa_hash          = nfa_hash;
-            nfa_table         = nfa_table;
-            nfa_start         = nfa_start;
-            nfa_actions       = actions;
-            nfa_search_start  = nfa_search_start;
-            nfa_search_states = nfa_search_states
-          } = nfa
-      in
+      let nfa_hash = nfa.nfa_hash in
+      let nfa_table = nfa.nfa_table in
+      let nfa_start = nfa.nfa_start in
+      let actions = nfa.nfa_actions in
+      let nfa_search_start = nfa.nfa_search_start in
+      let nfa_search_states = nfa.nfa_search_states in
       let dfa_hash = DfaState.create_state () in
       let nfa_start = DfaState.create dfa_hash [nfa_start] in
       let start =
@@ -2673,8 +2631,8 @@ struct
     * then we have seen all the rest of the clauses too.
     *)
    let union info1 info2 =
-      let { lex_exp = exp1 } = info1 in
-      let { lex_exp = exp2 } = info2 in
+      let exp1 = info1.lex_exp in
+      let exp2 = info2.lex_exp in
          (* Catch degenerate cases first *)
          match exp1.exp_clauses, exp2.exp_clauses with
             [], _ -> info2
@@ -2711,7 +2669,7 @@ struct
       ignore (dfa_of_info info)
 
    let pp_print_lexer buf info =
-      let { lex_exp = exp } = info in
+      let exp = info.lex_exp in
       let dfa = dfa_of_info info in
          fprintf buf "@[<v 0>@[<hv 3>Lexer:@ %a@]" pp_print_exp exp;
          fprintf buf "@ @[<hv 3>NFA:";
