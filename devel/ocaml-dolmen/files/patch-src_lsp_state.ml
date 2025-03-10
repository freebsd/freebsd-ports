--- src/lsp/state.ml.orig	2024-08-15 00:34:51 UTC
+++ src/lsp/state.ml
@@ -45,7 +45,7 @@ let warn ?file:_ ?loc t warn payload =
   in
   Format.kfprintf (fun _ ->
       let msg = Format.flush_str_formatter () in
-      let d = Diagnostic.warn ~loc msg in
+      let d = Diagnostic.warn ~loc (`String msg) in
       add_diag d t) Format.str_formatter "%a"
     Dolmen_loop.Report.Warning.print (warn, payload)
 
@@ -67,7 +67,7 @@ let error ?file:_ ?loc t err payload =
   (* Print the error message *)
   Format.kfprintf (fun _ ->
       let msg = Format.flush_str_formatter () in
-      let d = Diagnostic.error ~loc msg in
+      let d = Diagnostic.error ~loc (`String msg) in
       add_diag d t) Format.str_formatter "%a"
     Dolmen_loop.Report.Error.print (err, payload)
 
