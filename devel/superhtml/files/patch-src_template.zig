--- src/template.zig.orig	2026-10-11 12:17:37 UTC
+++ src/template.zig
@@ -1242,12 +1242,12 @@ pub fn SuperTemplate(comptime ScriptyVM: type) type {
         }
 
         pub fn setContext(tpl: Template, script_ctx: RootRef) void {
-            script_ctx.loop = if (tpl.loop_stack.getLast()) |last|
+            script_ctx.loop = if (tpl.loop_stack.getLastOrNull()) |last|
                 last.iterator
             else
                 null;
 
-            script_ctx.@"if" = if (tpl.if_stack.getLast()) |last|
+            script_ctx.@"if" = if (tpl.if_stack.getLastOrNull()) |last|
                 last.value
             else
                 null;
