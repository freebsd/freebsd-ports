$NetBSD: patch-ag,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/env/omake_env.ml.orig	2008-01-15 19:57:00.000000000 +0000
+++ src/env/omake_env.ml
@@ -404,8 +404,8 @@ let rec pp_print_command buf command =
    match command with
       CommandSection (arg, fv, e) ->
          fprintf buf "@[<hv 3>section %a@ %a@]" pp_print_value arg pp_print_exp_list e
-    | CommandValue (_, v) ->
-         pp_print_value buf v
+    | CommandValue (_, _, v) ->
+         pp_print_string_exp buf v
 
 and pp_print_commands buf commands =
    List.iter (fun command -> fprintf buf "@ %a" pp_print_command command) commands
@@ -1928,6 +1928,14 @@ let venv_save_explicit_rules venv loc er
 let venv_add_wild_match venv v =
    venv_add_var venv wild_var v
 
+let command_add_wild venv wild command =
+   match command with
+      CommandSection _ ->
+         command
+    | CommandValue(loc, env, s) ->
+         let env = venv_get_env (venv_add_wild_match (venv_with_env venv env) wild) in
+            CommandValue(loc, env, s)
+
 (*
  * This is the standard way to add results of a pattern match.
  *)
@@ -2699,8 +2707,10 @@ let venv_find_implicit_rules_inner venv 
                         let scanner_args = List.map (subst_source venv target_dir subst) irule.irule_scanners in
                         let scanners = node_set_of_list scanner_args in
                         let core = wild_core subst in
-                        let venv = venv_add_wild_match venv (ValData core) in
-                        let commands = make_command_info venv source_args irule.irule_values irule.irule_body in
+                        let core_val = ValData core in
+                        let venv = venv_add_wild_match venv core_val in
+                        let commands = List.map (command_add_wild venv core_val) irule.irule_body in
+                        let commands = make_command_info venv source_args irule.irule_values commands in
                         let effects =
                            List.fold_left (fun effects pattern ->
                                  let effect = wild_subst_in subst pattern in
