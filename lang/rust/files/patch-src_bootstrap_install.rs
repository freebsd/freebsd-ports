--- src/bootstrap/install.rs.orig	2017-02-09 01:37:48 UTC
+++ src/bootstrap/install.rs
@@ -13,9 +13,9 @@
 //! This module is responsible for installing the standard library,
 //! compiler, and documentation.
 
+use std::env;
 use std::fs;
-use std::borrow::Cow;
-use std::path::Path;
+use std::path::{Path, PathBuf, Component};
 use std::process::Command;
 
 use Build;
@@ -23,23 +23,35 @@ use dist::{package_vers, sanitize_sh, tm
 
 /// Installs everything.
 pub fn install(build: &Build, stage: u32, host: &str) {
-    let prefix = build.config.prefix.as_ref().clone().map(|x| Path::new(x))
-        .unwrap_or(Path::new("/usr/local"));
-    let docdir = build.config.docdir.as_ref().clone().map(|x| Cow::Borrowed(Path::new(x)))
-        .unwrap_or(Cow::Owned(prefix.join("share/doc/rust")));
-    let libdir = build.config.libdir.as_ref().clone().map(|x| Cow::Borrowed(Path::new(x)))
-        .unwrap_or(Cow::Owned(prefix.join("lib")));
-    let mandir = build.config.mandir.as_ref().clone().map(|x| Cow::Borrowed(Path::new(x)))
-        .unwrap_or(Cow::Owned(prefix.join("share/man")));
+    let prefix_default = PathBuf::from("/usr/local");
+    let docdir_default = PathBuf::from("share/doc/rust");
+    let mandir_default = PathBuf::from("share/man");
+    let libdir_default = PathBuf::from("lib");
+    let prefix = build.config.prefix.as_ref().unwrap_or(&prefix_default);
+    let docdir = build.config.docdir.as_ref().unwrap_or(&docdir_default);
+    let libdir = build.config.libdir.as_ref().unwrap_or(&libdir_default);
+    let mandir = build.config.mandir.as_ref().unwrap_or(&mandir_default);
+
+    let docdir = prefix.join(docdir);
+    let libdir = prefix.join(libdir);
+    let mandir = prefix.join(mandir);
+
+    let destdir = env::var_os("DESTDIR").map(PathBuf::from);
+
+    let prefix = add_destdir(&prefix, &destdir);
+    let docdir = add_destdir(&docdir, &destdir);
+    let libdir = add_destdir(&libdir, &destdir);
+    let mandir = add_destdir(&mandir, &destdir);
+
     let empty_dir = build.out.join("tmp/empty_dir");
     t!(fs::create_dir_all(&empty_dir));
     if build.config.docs {
-        install_sh(&build, "docs", "rust-docs", stage, host, prefix,
+        install_sh(&build, "docs", "rust-docs", stage, host, &prefix,
                    &docdir, &libdir, &mandir, &empty_dir);
     }
-    install_sh(&build, "std", "rust-std", stage, host, prefix,
+    install_sh(&build, "std", "rust-std", stage, host, &prefix,
                &docdir, &libdir, &mandir, &empty_dir);
-    install_sh(&build, "rustc", "rustc", stage, host, prefix,
+    install_sh(&build, "rustc", "rustc", stage, host, &prefix,
                &docdir, &libdir, &mandir, &empty_dir);
     t!(fs::remove_dir_all(&empty_dir));
 }
@@ -59,3 +71,17 @@ fn install_sh(build: &Build, package: &s
        .arg("--disable-ldconfig");
     build.run(&mut cmd);
 }
+
+fn add_destdir(path: &Path, destdir: &Option<PathBuf>) -> PathBuf {
+    let mut ret = match *destdir {
+        Some(ref dest) => dest.clone(),
+        None => return path.to_path_buf(),
+    };
+    for part in path.components() {
+        match part {
+            Component::Normal(s) => ret.push(s),
+            _ => {}
+        }
+    }
+    return ret
+}
