--- src/main.rs.orig	2024-03-04 21:09:32 UTC
+++ src/main.rs
@@ -230,20 +230,20 @@ fn main() -> Result<()> {
      * folder */
     let corpus_dir = match corpus_dir_res {
         Some(c) => c.to_owned(),
-        None => if Path::new("cpu_rec_corpus").is_dir() {
-            "cpu_rec_corpus".to_string()
+        None => if Path::new("%%CORPUS_DIR%%").is_dir() {
+            "%%CORPUS_DIR%%".to_string()
         } else {
             let exe_path = std::env::current_exe().with_context(|| "Could not get exe filename")?;
             let parent_path = exe_path.parent().unwrap();
-            if parent_path.join("cpu_rec_corpus").is_dir() {
+            if parent_path.join("%%CORPUS_DIR%%").is_dir() {
                 // Found it in the exe path
                 parent_path
-                    .join("cpu_rec_corpus")
+                    .join("%%CORPUS_DIR%%")
                     .to_str()
                     .unwrap()
                     .to_string()
             } else {
-                bail!("Could not find \"cpu_rec_corpus\", please specify it using --corpus");
+                bail!("Could not find \"%%CORPUS_DIR%%\", please specify it using --corpus");
             }
         }
         .to_owned(),
