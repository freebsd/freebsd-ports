--- third_party/ffmpeg/chromium/scripts/robo_lib/config.py.orig	2023-10-19 19:59:38 UTC
+++ third_party/ffmpeg/chromium/scripts/robo_lib/config.py
@@ -35,7 +35,7 @@ class RoboConfiguration:
     self._patches_commit_title = "Chromium patches file"
     # Title of the commit with README.chromium
     self._readme_chromium_commit_title = "README.chromium file"
-    self.EnsureHostInfo()
+    #self.EnsureHostInfo()
     self.EnsureChromeSrc()
     self.EnsureScriptDirectory()
 
@@ -47,18 +47,15 @@ class RoboConfiguration:
     self._llvm_path = os.path.join(self.chrome_src(), "third_party",
             "llvm-build", "Release+Asserts", "bin")
 
-    self.EnsurePathContainsLLVM()
-    self.EnsureNoMakeInfo()
+    #self.EnsurePathContainsLLVM()
+    #self.EnsureNoMakeInfo()
     self.EnsureFFmpegHome()
     self.EnsureASANConfig()
-    self.ComputeBranchName()
+    #self.ComputeBranchName()
     if not quiet:
       shell.log(f"Using chrome src: {self.chrome_src()}")
       shell.log(f"Using script dir: {self._script_directory}")
       shell.log(f"Using ffmpeg home:{self.ffmpeg_home()}")
-      shell.log(f"On branch: {self.branch_name()}")
-      if self.sushi_branch_name():
-        shell.log(f"On sushi branch: {self.sushi_branch_name()}")
 
     # Filename that we'll ask generate_gn.py to write git commands to.
     # TODO: Should this use script_directory, or stay with ffmpeg?  As long as
@@ -149,7 +146,7 @@ class RoboConfiguration:
     """Ensure that the host architecture and platform are set."""
     kernel, host, os, *rest = shell.output_or_error(["uname", "-a"]).split()
     assert kernel in ("Linux", "linux")
-    assert "x86_64" in rest
+    assert ("x86_64", "amd64") in rest
     self._host_operating_system = "linux"
     self._host_architecture = "x64"
 
@@ -165,8 +162,8 @@ class RoboConfiguration:
     wd = os.getcwd()
     # Walk up the tree until we find src/AUTHORS
     while wd != "/":
-      if os.path.isfile(os.path.join(wd, "src", "AUTHORS")):
-        self._chrome_src = os.path.join(wd, "src")
+      if os.path.isfile(os.path.join(wd, "third_party", "DEPS")):
+        self._chrome_src = wd
         return
       wd = os.path.dirname(wd)
     raise Exception("could not find src/AUTHORS in any parent of the wd")
