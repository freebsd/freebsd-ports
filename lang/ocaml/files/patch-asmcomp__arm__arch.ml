--- ./asmcomp/arm/arch.ml.orig	2014-04-28 13:12:11.000000000 +0100
+++ ./asmcomp/arm/arch.ml	2014-04-28 13:12:36.000000000 +0100
@@ -21,7 +21,7 @@
 
 let abi =
   match Config.system with
-    "linux_eabi"   -> EABI
+    "linux_eabi" | "freebsd" -> EABI
   | "linux_eabihf" -> EABI_HF
   | _ -> assert false
 
