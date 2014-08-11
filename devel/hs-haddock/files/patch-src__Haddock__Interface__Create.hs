--- ./src/Haddock/Interface/Create.hs.orig	2014-04-02 23:25:15.000000000 +0200
+++ ./src/Haddock/Interface/Create.hs	2014-07-14 06:40:22.000000000 +0200
@@ -364,7 +364,7 @@
   where
     decls = docs ++ defs ++ sigs ++ ats
     docs  = mkDecls tcdDocs DocD class_
-    defs  = mkDecls (map snd . bagToList . tcdMeths) ValD class_
+    defs  = mkDecls (bagToList . tcdMeths) ValD class_
     sigs  = mkDecls tcdSigs SigD class_
     ats   = mkDecls tcdATs (TyClD . FamDecl) class_
 
@@ -390,7 +390,7 @@
   mkDecls hs_docs                          DocD   group_ ++
   mkDecls hs_instds                        InstD  group_ ++
   mkDecls (typesigs . hs_valds)            SigD   group_ ++
-  mkDecls (map snd . valbinds . hs_valds)  ValD   group_
+  mkDecls (valbinds . hs_valds)  ValD   group_
   where
     typesigs (ValBindsOut _ sigs) = filter isVanillaLSig sigs
     typesigs _ = error "expected ValBindsOut"
