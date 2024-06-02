--- build.rs.orig	2024-06-02 12:49:32 UTC
+++ build.rs
@@ -1,27 +1,7 @@ fn get_git_hash() -> String {
 use chrono::TimeZone;
 
 fn get_git_hash() -> String {
-	use std::process::Command;
-
-	// Allow builds from `git archive` generated tarballs if output of `git get-tar-commit-id` is
-	// set in an env var.
-	if let Ok(commit) = std::env::var("BUILD_GIT_COMMIT_ID") {
-		return commit[..7].to_string();
-	};
-	let commit = Command::new("git")
-		.arg("rev-parse")
-		.arg("--short=7")
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
