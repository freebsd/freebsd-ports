--- compiler/rustc_llvm/build.rs
+++ compiler/rustc_llvm/build.rs
@@ -237,18 +237,20 @@
 
     if !is_crossed {
         cmd.arg("--system-libs");
-    } else if target.contains("windows-gnu") {
-        println!("cargo:rustc-link-lib=shell32");
-        println!("cargo:rustc-link-lib=uuid");
-    } else if target.contains("netbsd") || target.contains("haiku") || target.contains("darwin") {
-        println!("cargo:rustc-link-lib=z");
-    } else if target.starts_with("arm")
-        || target.starts_with("mips-")
+    }
+
+    if target.starts_with("mips")
         || target.starts_with("mipsel-")
         || target.starts_with("powerpc-")
     {
         // 32-bit targets need to link libatomic.
         println!("cargo:rustc-link-lib=atomic");
+        println!("cargo:rustc-link-lib=z");
+    } else if target.contains("windows-gnu") {
+        println!("cargo:rustc-link-lib=shell32");
+        println!("cargo:rustc-link-lib=uuid");
+    } else if target.contains("netbsd") || target.contains("haiku") || target.contains("darwin") {
+        println!("cargo:rustc-link-lib=z");
     }
     cmd.args(&components);
 
