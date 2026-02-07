--- src/lsp/server.ml.orig	2024-08-15 00:37:20 UTC
+++ src/lsp/server.ml
@@ -55,14 +55,14 @@ class dolmen_lsp_server =
       let change = Lsp.Types.TextDocumentSyncKind.Incremental in
       (* Lsp.Types.TextDocumentSyncKind.Full *)
       Lsp.Types.TextDocumentSyncOptions.create ~openClose:true ~change
-        ~save:(Lsp.Types.SaveOptions.create ~includeText:false ())
+        ~save:(`SaveOptions (Lsp.Types.SaveOptions.create ~includeText:false ()))
         ()
 
     method private _on_doc
         ~(notify_back:Linol_lwt.Jsonrpc2.notify_back)
         (uri:Lsp.Types.DocumentUri.t) (contents:string) =
       (* TODO: unescape uri/translate it to a correct path ? *)
-      match Loop.process prelude (preprocess_uri uri) (Some contents) with
+      match Loop.process prelude (Lsp.Uri.to_path uri) (Some contents) with
       | Ok state ->
         let diags = State.get State.diagnostics state in
         Hashtbl.replace buffers uri state;
@@ -94,5 +94,7 @@ class dolmen_lsp_server =
     method on_notif_doc_did_close ~notify_back d =
       Hashtbl.remove buffers d.uri;
       notify_back#send_diagnostic []
+
+    method spawn_query_handler = Lwt.async
 
   end
