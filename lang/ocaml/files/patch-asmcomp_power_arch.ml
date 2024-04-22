--- asmcomp/power/arch.ml.orig	2024-02-01 14:00:12 UTC
+++ asmcomp/power/arch.ml
@@ -28,7 +28,7 @@ let abi =
 let abi =
   match Config.model with
   | "ppc" -> ELF32
-  | "ppc64" -> ELF64v1
+  | "ppc64" -> ELF64v2
   | "ppc64le" -> ELF64v2
   | _ -> assert false
 
