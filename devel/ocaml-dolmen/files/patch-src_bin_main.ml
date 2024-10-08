--- src/bin/main.ml.orig	2024-08-15 00:57:27 UTC
+++ src/bin/main.ml
@@ -127,22 +127,21 @@ let () =
   let exits =
     List.map (fun code ->
         let retcode, doc = Dolmen_loop.Code.descr code in
-        Cmdliner.Cmd.Exit.info ~doc retcode
+        Cmdliner.Term.exit_info ~doc retcode
       ) (Dolmen_loop.Code.errors ())
-    @ Cmdliner.Cmd.Exit.defaults
+    @ Cmdliner.Term.default_exits
   in
-  let cli_term = Cmdliner.Cmd.v
-      (Cmdliner.Cmd.info "dolmen" ~exits ~man:Man.cli ~version)
-      Options.cli
+  let cli_info =
+      (Cmdliner.Term.info "dolmen" ~exits ~man:Man.cli ~version)
   in
-  match Cmdliner.Cmd.eval_value cli_term with
-  | Ok (`Version | `Help) ->
+  match Cmdliner.Term.eval (Options.cli,  cli_info) with
+  | `Version | `Help ->
     exit 0
-  | Error (`Parse | `Term | `Exn) ->
-    exit Cmdliner.Cmd.Exit.cli_error
-  | Ok (`Ok Run { state ; preludes; logic_file }) ->
+  | `Error (`Parse | `Term | `Exn) ->
+    exit Cmdliner.Term.exit_status_cli_error
+  | `Ok (Run { state ; preludes; logic_file }) ->
     run state preludes logic_file
-  | Ok (`Ok Doc { report; conf; }) ->
+  | `Ok (Doc { report; conf; }) ->
     doc conf report
-  | Ok (`Ok List_reports { conf; }) ->
+  | `Ok (List_reports { conf; }) ->
     list conf
