--- build.zig.orig	2026-10-11 11:59:12 UTC
+++ build.zig
@@ -76,7 +76,7 @@ pub fn build(b: *std.Build) !void {
     setupFuzzStep(b, target, test_step, superhtml);
 
     const release = b.step("release", "Create release builds of SuperHTML");
-    const git_version = getGitVersion(b);
+    const git_version = @unionInit(Version, "tag", "%%PORTVERSION%%");
     if (git_version == .tag) {
         if (std.mem.eql(u8, version, git_version.tag[1..])) {
             setupReleaseStep(
