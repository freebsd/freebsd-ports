--- ghc/compiler/nativeGen/MachMisc.lhs.orig	Thu Dec 11 11:42:12 2003
+++ ghc/compiler/nativeGen/MachMisc.lhs	Thu Dec 11 11:44:02 2003
@@ -71,11 +71,11 @@
 fmtAsmLbl :: String -> String  -- for formatting labels
 
 fmtAsmLbl s
-  =  IF_ARCH_alpha(
      {- The alpha assembler likes temporary labels to look like $L123
 	instead of L123.  (Don't toss the L, because then Lf28
 	turns into $f28.)
      -}
+  =  IF_ARCH_alpha(
      '$' : s
      ,{-otherwise-}
      '.':'L':s
