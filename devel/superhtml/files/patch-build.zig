--- build.zig.orig	2026-06-09 15:40:29 UTC
+++ build.zig
@@ -228,7 +228,7 @@ fn setupCliTool(
     super_cli.root_module.addOptions("build_options", options);
 
     const run_exe = b.addRunArtifact(super_cli);
-    run_exe.addPassthruArgs();
+    if (b.args) |args| run_exe.addArgs(args);
     const run_exe_step = b.step("run", "Run the SuperHTML CLI");
     run_exe_step.dependOn(&run_exe.step);
 
@@ -429,14 +429,14 @@ fn getGitVersion(b: *std.Build) Version {
 };
 
 fn getGitVersion(b: *std.Build) Version {
-    const git_path = b.findProgram(.{ .names = &.{"git"} }) orelse return .unknown;
+    const git_path = b.findProgram(&.{"git"}, &.{}) catch return .unknown;
     var out: u8 = undefined;
     const git_describe = std.mem.trim(
         u8,
         b.runAllowFail(&[_][]const u8{
-            git_path,               "-C",
-            b.root.root_dir.path.?, "describe",
-            "--match",              "*.*.*",
+            git_path,            "-C",
+            b.build_root.path.?, "describe",
+            "--match",           "*.*.*",
             "--tags",
         }, &out, .ignore) catch return .unknown,
         " \n\r",
