--- asmcomp/power/arch.ml.orig	2019-12-02 10:44:34 UTC
+++ asmcomp/power/arch.ml
@@ -28,7 +28,7 @@ type abi = ELF32 | ELF64v1 | ELF64v2
 let abi =
   match Config.model with
   | "ppc" -> ELF32
-  | "ppc64" -> ELF64v1
+  | "ppc64" -> ELF64v2
   | "ppc64le" -> ELF64v2
   | _ -> assert false
 
