--- src/zig/build.zig.orig	2026-03-20 08:48:48 UTC
+++ src/zig/build.zig
@@ -18,6 +18,7 @@ pub fn build(b: *std.Build) void {
             .target = target,
             .root_source_file = b.path("vcf.zig"),
             .pic = true,
+            .stack_check = false, // consumed by ld.lld (not Zig). Drop runtime stack probes to avoid undefined __zig_probe_stack
         }),
     });
     // lib.addObjectFile("../../build/libvcflib.a"); circular dependency
