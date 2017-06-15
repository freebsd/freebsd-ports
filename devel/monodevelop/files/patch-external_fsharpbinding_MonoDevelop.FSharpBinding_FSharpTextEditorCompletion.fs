--- external/fsharpbinding/MonoDevelop.FSharpBinding/FSharpTextEditorCompletion.fs.orig	2016-09-22 11:49:00 UTC
+++ external/fsharpbinding/MonoDevelop.FSharpBinding/FSharpTextEditorCompletion.fs
@@ -100,10 +100,10 @@ type FsiMemberCompletionData(displayText
                     async {
                         let! tooltip = Async.AwaitEvent (session.TooltipReceived)
                         match tooltip with
-                        | MonoDevelop.FSharp.Shared.ToolTip (signature, xmldoc, footer) ->
+                        | MonoDevelop.FSharp.Shared.ToolTips.ToolTip (signature, xmldoc, footer) ->
                             let! tooltipInfo = SymbolTooltips.getTooltipInformationFromTip (signature, xmldoc, footer)
                             return tooltipInfo
-                        | MonoDevelop.FSharp.Shared.EmptyTip ->
+                        | MonoDevelop.FSharp.Shared.ToolTips.EmptyTip ->
                             return TooltipInformation()
                     }
                 Async.StartAsTask(computation, cancellationToken = cancel)
