--- ltsmaster/driver/targetmachine.cpp 2018-08-24 00:55:46 UTC
+++ ltsmaster/driver/targetmachine.cpp
@@ -587,6 +587,23 @@
     break;
   }
 
+  // Taken from clang's lib/Driver/ToolChains/Gnu.cpp
+  if (triple.getArch() == llvm::Triple::aarch64 ||
+      triple.getArch() == llvm::Triple::aarch64_be ||
+      (triple.getOS() == llvm::Triple::FreeBSD &&
+       triple.getOSMajorVersion() >= 12) ||
+      triple.getOS() == llvm::Triple::NaCl ||
+      (triple.getVendor() == llvm::Triple::MipsTechnologies &&
+       !triple.hasEnvironment()) ||
+      triple.getOS() == llvm::Triple::Solaris
+#if LDC_LLVM_VER >= 400
+      || triple.getArch() == llvm::Triple::riscv32
+      || triple.getArch() == llvm::Triple::riscv64
+#endif
+      ) {
+    targetOptions.UseInitArray = true;
+  }
+
   // Right now, we only support linker-level dead code elimination on Linux
   // using the GNU toolchain (based on ld's --gc-sections flag). The Apple ld
   // on OS X supports a similar flag (-dead_strip) that doesn't require

