--- tests/build-auth.rs.orig	2016-12-20 21:16:05 UTC
+++ tests/build-auth.rs
@@ -41,7 +41,7 @@ fn http_auth_offered() {
         assert_eq!(req, vec![
             "GET /foo/bar/info/refs?service=git-upload-pack HTTP/1.1",
             "Accept: */*",
-            "User-Agent: git/1.0 (libgit2 0.24.0)",
+            "User-Agent: git/2.0 (libgit2 0.25.0)",
         ].into_iter().map(|s| s.to_string()).collect());
         drop(s);
 
@@ -56,7 +56,7 @@ fn http_auth_offered() {
             "GET /foo/bar/info/refs?service=git-upload-pack HTTP/1.1",
             "Authorization: Basic Zm9vOmJhcg==",
             "Accept: */*",
-            "User-Agent: git/1.0 (libgit2 0.24.0)",
+            "User-Agent: git/2.0 (libgit2 0.25.0)",
         ].into_iter().map(|s| s.to_string()).collect());
     });
 
