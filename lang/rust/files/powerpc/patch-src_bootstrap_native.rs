--- src/bootstrap/native.rs.orig	2021-05-03 20:57:16.000000000 +0000
+++ src/bootstrap/native.rs	2021-05-06 20:37:55.448200000 +0000
@@ -118,6 +118,10 @@ impl Step for Llvm {
             let idx = target.triple.find('-').unwrap();
 
             format!("riscv{}{}", &target.triple[5..7], &target.triple[idx..])
+        } else if self.target.starts_with("powerpc") && self.target.ends_with("freebsd") {
+            // FreeBSD 13 had incompatible ABI changes on all PowerPC platforms.
+            // Set the version suffix to 13.0 so the correct target details are used.
+            format!("{}{}", self.target, "13.0")
         } else {
             target.to_string()
         };
@@ -274,6 +278,11 @@ impl Step for Llvm {
             if num_linkers > 0 {
                 cfg.define("LLVM_PARALLEL_LINK_JOBS", num_linkers.to_string());
             }
+        }
+
+        // Workaround for ppc32 lld limitation
+        if target == "powerpc-unknown-freebsd" {
+            cfg.define("CMAKE_EXE_LINKER_FLAGS", "-fuse-ld=bfd");
         }
 
         // http://llvm.org/docs/HowToCrossCompileLLVM.html
