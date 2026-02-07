--- src/main.rs.orig	2023-06-22 09:40:27 UTC
+++ src/main.rs
@@ -198,7 +198,7 @@ fn main() -> Result<()> {
         .propagate_version(true)
         .author("Raphaël Rigo <devel@syscall.eu>")
         .about("Identifies CPU architectures in binaries")
-        .arg(arg!(--corpus <corpus_dir>).default_value("cpu_rec_corpus"))
+        .arg(arg!(--corpus <corpus_dir>).default_value("%%CORPUS_DIR%%"))
         .arg(arg!(-d - -debug))
         .arg(arg!(-v - -verbose))
         .arg(
