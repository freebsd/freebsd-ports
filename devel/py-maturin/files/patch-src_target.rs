--- src/target.rs.orig	2021-10-27 17:18:18 UTC
+++ src/target.rs
@@ -72,7 +72,7 @@ fn get_supported_architectures(os: &Os) -> Vec<Arch> {
         ],
         Os::Windows => vec![Arch::X86, Arch::X86_64, Arch::Aarch64],
         Os::Macos => vec![Arch::Aarch64, Arch::X86_64],
-        Os::FreeBsd => vec![Arch::X86_64, Arch::Aarch64],
+        Os::FreeBsd => vec![Arch::X86_64, Arch::Aarch64, Arch::Powerpc64, Arch::Powerpc64Le],
         Os::OpenBsd => vec![Arch::X86, Arch::X86_64, Arch::Aarch64],
     }
 }
@@ -143,6 +143,8 @@ impl Target {
         match (&self.os, &self.arch) {
             (Os::FreeBsd, Arch::X86_64)
             | (Os::FreeBsd, Arch::Aarch64)
+            | (Os::FreeBsd, Arch::Powerpc64)
+            | (Os::FreeBsd, Arch::Powerpc64Le)
             | (Os::OpenBsd, Arch::X86)
             | (Os::OpenBsd, Arch::X86_64)
             | (Os::OpenBsd, Arch::Aarch64) => {
@@ -155,6 +157,8 @@ impl Target {
                     Arch::X86_64 => "amd64",
                     Arch::X86 => "i386",
                     Arch::Aarch64 => "arm64",
+                    Arch::Powerpc64 => "powerpc64",
+                    Arch::Powerpc64Le => "powerpc64le",
                     _ => panic!(
                         "unsupported architecutre should not have reached get_platform_tag()"
                     ),
