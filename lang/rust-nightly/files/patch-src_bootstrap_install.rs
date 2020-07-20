https://github.com/rust-lang/rust/issues/74545

--- src/bootstrap/install.rs.orig	2020-07-20 14:00:24 UTC
+++ src/bootstrap/install.rs
@@ -112,9 +112,14 @@ fn install_sh(
         pkgname(builder, name)
     };
 
+    let install_script = tmpdir(builder).join(&package_name).join("install.sh");
+    if !install_script.exists() {
+        return;
+    }
+
     let mut cmd = Command::new("sh");
     cmd.current_dir(&empty_dir)
-        .arg(sanitize_sh(&tmpdir(builder).join(&package_name).join("install.sh")))
+        .arg(sanitize_sh(&install_script))
         .arg(format!("--prefix={}", sanitize_sh(&prefix)))
         .arg(format!("--sysconfdir={}", sanitize_sh(&sysconfdir)))
         .arg(format!("--datadir={}", sanitize_sh(&datadir)))
