--- build.rs.orig	2024-04-15 23:07:43 UTC
+++ build.rs
@@ -1,20 +1,5 @@ fn get_git_hash() -> String {
 fn get_git_hash() -> String {
-	use std::process::Command;
-
-	let commit = Command::new("git")
-		.arg("rev-parse")
-		.arg("--short")
-		.arg("--verify")
-		.arg("HEAD")
-		.output();
-	if let Ok(commit_output) = commit {
-		let commit_string =
-			String::from_utf8_lossy(&commit_output.stdout);
-
-		return commit_string.lines().next().unwrap_or("").into();
-	}
-
-	panic!("Can not get git commit: {}", commit.unwrap_err());
+	return format!("n/a");
 }
 
 fn main() {
