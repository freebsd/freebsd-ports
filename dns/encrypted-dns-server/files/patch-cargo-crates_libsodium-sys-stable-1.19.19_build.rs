--- cargo-crates/libsodium-sys-stable-1.19.19/build.rs.orig	2021-10-11 05:09:34 UTC
+++ cargo-crates/libsodium-sys-stable-1.19.19/build.rs
@@ -225,6 +225,7 @@ fn make_libsodium(target: &str, source_dir: &Path, ins
         cross_compiling = true;
         help = "";
     } else {
+        cflags += " -fuse-ld=lld";
         if target.contains("i686") {
             compiler += " -m32 -maes";
             cflags += " -march=i686";
