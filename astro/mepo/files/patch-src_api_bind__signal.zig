https://lists.sr.ht/~mil/mepo-devel/patches/38775

--- src/api/bind_signal.zig.orig	2023-02-01 03:43:08 UTC
+++ src/api/bind_signal.zig
@@ -39,13 +39,14 @@ fn bind_signal(mepo: *Mepo, signo_str: [:0]const u8, expression: []const u8) !vo
     }
 
     // Register generic signal handler
-    if (0 != std.os.linux.sigaction(signal_name, &.{
+    const signal_action = std.os.Sigaction{
         .handler = .{ .handler = utilsdl.sdl_push_event_signal },
-        .mask = [_]u32{0} ** 32,
-        .flags = @as(c_uint, 0),
-    }, null)) {
-        return error.FailedToSetupSighandler;
-    }
+        .mask = std.os.empty_sigset,
+        .flags = 0,
+    };
+
+    std.os.sigaction(signal_name, &signal_action, null)
+        catch return error.FailedToSetupSighandler;
 
     if (mepo.table_signals.get(signal_name)) |heap_str| {
         mepo.allocator.free(heap_str);
