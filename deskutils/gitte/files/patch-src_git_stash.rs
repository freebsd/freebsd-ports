--- src/git/stash.rs.orig	2026-10-15 10:31:44 UTC
+++ src/git/stash.rs
@@ -34,18 +34,17 @@ pub(super) fn load_stashes(repo: &mut git2::Repository
 pub(super) fn load_stashes(repo: &mut git2::Repository) -> Vec<StashEntry> {
     let mut stashes = Vec::new();
 
-    repo.stash_foreach(|index, message, oid| {
-        stashes.push(StashEntry {
-            index,
-            message: message.to_string(),
-            oid: oid.to_string(),
-            base_oid: None,
-            time: 0,
-        });
-
-        true
-    })
-    .ok();
+    if let Ok(reflog) = repo.reflog("refs/stash") {
+        for (index, entry) in reflog.iter().enumerate() {
+            stashes.push(StashEntry {
+                index,
+                message: String::from_utf8_lossy(entry.message_bytes().unwrap_or_default()).into_owned(),
+                oid: entry.id_new().to_string(),
+                base_oid: None,
+                time: 0,
+            });
+        }
+    }
 
     for entry in &mut stashes {
         if let Ok(oid) = git2::Oid::from_str(&entry.oid)
