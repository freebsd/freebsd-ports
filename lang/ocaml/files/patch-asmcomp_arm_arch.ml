commit 41c5035f3715650d5f0e2668b721d204a87ab6eb
Author: John F. Carr <jfc@mit.edu>
Date:   Sat Oct 24 10:15:35 2026 -0400

    FreeBSD on armv6+ has used the hard float ABI since release 11

diff --git a/asmcomp/arm/arch.ml b/asmcomp/arm/arch.ml
index ee4ca76d44..a86c740b4a 100644
--- asmcomp/arm/arch.ml
+++ asmcomp/arm/arch.ml
@@ -24,8 +24,8 @@ type fpu = Soft | VFPv2 | VFPv3_D16 | VFPv3
 
 let abi =
   match Config.system with
-    "linux_eabi" | "freebsd" -> EABI
-  | "linux_eabihf" | "netbsd" -> EABI_HF
+    "linux_eabi" -> EABI
+  | "linux_eabihf" | "netbsd" | "freebsd" -> EABI_HF
   | _ -> assert false
 
 let string_of_arch = function
