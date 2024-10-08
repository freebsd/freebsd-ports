--- src/server.ml.orig	2024-05-29 17:37:32 UTC
+++ src/server.ml
@@ -496,7 +496,18 @@ module Make (IO : IO) = struct
           | Lsp.Client_request.CallHierarchyOutgoingCalls _
           | Lsp.Client_request.WillCreateFiles _
           | Lsp.Client_request.WillDeleteFiles _
-          | Lsp.Client_request.WillRenameFiles _ ->
+          | Lsp.Client_request.WillRenameFiles _
+          | Lsp.Client_request.InlayHintResolve _
+          | Lsp.Client_request.TextDocumentDiagnostic _
+          | Lsp.Client_request.TextDocumentInlineCompletion _
+          | Lsp.Client_request.TextDocumentInlineValue _
+          | Lsp.Client_request.TextDocumentPrepareTypeHierarchy _
+          | Lsp.Client_request.TextDocumentRangesFormatting _
+          | Lsp.Client_request.WorkspaceSymbolResolve _
+          | Lsp.Client_request.WorkspaceDiagnostic _
+          | Lsp.Client_request.TypeHierarchySubtypes _
+          | Lsp.Client_request.TypeHierarchySupertypes _
+ ->
             let notify_back =
               new notify_back
                 ~workDoneToken:None ~partialResultToken:None ~notify_back
@@ -666,7 +677,11 @@ module Make (IO : IO) = struct
         | Lsp.Client_notification.DidCreateFiles _
         | Lsp.Client_notification.DidDeleteFiles _
         | Lsp.Client_notification.WorkDoneProgress _
-        | Lsp.Client_notification.DidRenameFiles _ ->
+        | Lsp.Client_notification.DidRenameFiles _
+        | Lsp.Client_notification.NotebookDocumentDidOpen _
+        | Lsp.Client_notification.NotebookDocumentDidChange _
+        | Lsp.Client_notification.NotebookDocumentDidSave _
+        | Lsp.Client_notification.NotebookDocumentDidClose _ ->
           let notify_back =
             new notify_back
               ~workDoneToken:None ~partialResultToken:None ~notify_back
