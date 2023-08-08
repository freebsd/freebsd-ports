Check for the OFFLINE_BUILD environment variable to prevent issuing the repo
sync that requires git and an internet connection.

--- build/configure/src/rust.rs.orig	2023-05-31 05:19:10 UTC
+++ build/configure/src/rust.rs
@@ -1,6 +1,8 @@
 // Copyright: Ankitects Pty Ltd and contributors
 // License: GNU AGPL, version 3 or later; http://www.gnu.org/licenses/agpl.html
 
+use std::env;
+
 use ninja_gen::action::BuildAction;
 use ninja_gen::build::FilesHandle;
 use ninja_gen::cargo::CargoBuild;
@@ -10,6 +12,7 @@ use ninja_gen::git::SyncSubmodule;
 use ninja_gen::cargo::CargoTest;
 use ninja_gen::cargo::RustOutput;
 use ninja_gen::git::SyncSubmodule;
+use ninja_gen::git::SyncSubmoduleOffline;
 use ninja_gen::glob;
 use ninja_gen::input::BuildInput;
 use ninja_gen::inputs;
@@ -27,18 +30,34 @@ fn prepare_translations(build: &mut Build) -> Result<(
 
 fn prepare_translations(build: &mut Build) -> Result<()> {
     // ensure repos are checked out
-    build.add(
-        "ftl:repo:core",
-        SyncSubmodule {
-            path: "ftl/core-repo",
-        },
-    )?;
-    build.add(
-        "ftl:repo:qt",
-        SyncSubmodule {
-            path: "ftl/qt-repo",
-        },
-    )?;
+    if env::var("OFFLINE_BUILD").is_ok() {
+        println!("OFFLINE_BUILD set, skipping git repository sync for translation files.");
+        build.add(
+            "ftl:repo:core",
+            SyncSubmoduleOffline {
+                path: "ftl/core-repo",
+            },
+        )?;
+        build.add(
+            "ftl:repo:qt",
+            SyncSubmoduleOffline {
+                path: "ftl/qt-repo",
+            },
+        )?;
+    } else {
+        build.add(
+            "ftl:repo:core",
+            SyncSubmodule {
+                path: "ftl/core-repo",
+            },
+        )?;
+        build.add(
+            "ftl:repo:qt",
+            SyncSubmodule {
+                path: "ftl/qt-repo",
+            },
+        )?;
+    }
     // build anki_i18n and spit out strings.json
     build.add(
         "rslib/i18n",
