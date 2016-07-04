$NetBSD: patch-ac,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/build/omake_rule.ml.orig	2010-10-07 19:59:08.000000000 +0000
+++ src/build/omake_rule.ml
@@ -768,7 +768,7 @@ let lazy_command venv pos command =
          let fv = free_vars_exp_list el in
             CommandSection (eval_string_exp venv pos s, fv, el)
     | ShellExp (loc, s) ->
-         CommandValue (loc, ValStringExp (venv_get_env venv, s))
+         CommandValue (loc, venv_get_env venv, s)
     | _ ->
          let fv = free_vars_exp command in
             CommandSection (ValData "eval", fv, [command])
@@ -1121,7 +1121,8 @@ and eval_rule venv loc target sources sl
             let commands = ([], CommandEval e) :: commands in
             let fv = free_vars_union fv fv' in
                commands, fv
-       | CommandValue (loc, v) ->
+       | CommandValue (loc, env, s) ->
+            let v = ValStringExp (env, s) in
             let commands =
                try
                   let flags, pipe = pipe_of_value venv find_alias options pos loc v in
