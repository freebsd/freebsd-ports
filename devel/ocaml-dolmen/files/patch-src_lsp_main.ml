--- src/lsp/main.ml.orig	2024-08-15 00:50:43 UTC
+++ src/lsp/main.ml
@@ -3,7 +3,7 @@ let run () =
 
 let run () =
   let s = new Server.dolmen_lsp_server in
-  let server = Linol_lwt.Jsonrpc2.create_stdio s in
+  let server = Linol_lwt.Jsonrpc2.create_stdio ~env:() s in
   let task = Linol_lwt.Jsonrpc2.run server in
   match Linol_lwt.run task with
   | () -> ()
