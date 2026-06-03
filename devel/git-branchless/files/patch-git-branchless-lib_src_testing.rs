-- Fix test failures due to missing tools in PATH on FreeBSD.
-- git-branchless tests construct a very restricted PATH that misses /usr/bin.
--
--- git-branchless-lib/src/testing.rs.orig	2026-06-01 15:49:57 UTC
+++ git-branchless-lib/src/testing.rs
@@ -182,15 +182,18 @@ impl Git {
             .expect("Unable to find git-branchless target directory");
         let bash = get_sh().expect("bash missing?");
         let bash_path = bash.parent().unwrap();
-        std::env::join_paths(vec![
+        let mut paths = vec![
             // For Git to be able to launch `git-branchless`.
-            branchless_path.as_os_str(),
+            branchless_path.to_path_buf(),
             // For our hooks to be able to call back into `git`.
-            self.git_exec_path.as_os_str(),
+            self.git_exec_path.clone(),
             // For branchless to manually invoke bash when needed.
-            bash_path.as_os_str(),
-        ])
-        .expect("joining paths")
+            bash_path.to_path_buf(),
+        ];
+        if let Some(path) = std::env::var_os("PATH") {
+            paths.extend(std::env::split_paths(&path));
+        }
+        std::env::join_paths(paths).expect("joining paths")
     }
 
     /// Get the environment variables needed to run git in the test environment.
