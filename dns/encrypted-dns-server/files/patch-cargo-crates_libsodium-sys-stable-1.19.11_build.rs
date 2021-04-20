--- cargo-crates/libsodium-sys-stable-1.19.15/build.rs.orig     2020-11-19 15:20:25 UTC
+++ cargo-crates/libsodium-sys-stable-1.19.15/build.rs
@@ -214,6 +214,7 @@ fn make_libsodium(target: &str, source_dir: &Path, ins
         cross_compiling = true;
         help = "";
     } else {
+        cflags += " -fuse-ld=lld";
         if target.contains("i686") {
             compiler += " -m32 -maes";
             cflags += " -march=i686 -fuse-ld=lld";
