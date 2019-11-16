Disable https://github.com/rust-lang/rust/commit/8d56bcc59c92 until
master port drops Python 2.x support.

--- src/bootstrap/bootstrap.py.orig	2019-11-13 20:12:18 UTC
+++ src/bootstrap/bootstrap.py
@@ -360,7 +360,7 @@ class RustBuild(object):
                  self.program_out_of_date(self.rustc_stamp())):
             if os.path.exists(self.bin_root()):
                 shutil.rmtree(self.bin_root())
-            tarball_suffix = '.tar.xz' if support_xz() else '.tar.gz'
+            tarball_suffix = '.tar.gz'
             filename = "rust-std-{}-{}{}".format(
                 rustc_channel, self.build, tarball_suffix)
             pattern = "rust-std-{}".format(self.build)
@@ -385,7 +385,7 @@ class RustBuild(object):
         if self.cargo().startswith(self.bin_root()) and \
                 (not os.path.exists(self.cargo()) or
                  self.program_out_of_date(self.cargo_stamp())):
-            tarball_suffix = '.tar.xz' if support_xz() else '.tar.gz'
+            tarball_suffix = '.tar.gz'
             filename = "cargo-{}-{}{}".format(cargo_channel, self.build,
                                               tarball_suffix)
             self._download_stage0_helper(filename, "cargo", tarball_suffix)
