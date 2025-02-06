--- _cabal_deps/gtk2hs-buildtools-0.13.11.0/c2hs/toplevel/C2HSConfig.hs.orig	2001-09-09 01:46:40 UTC
+++ _cabal_deps/gtk2hs-buildtools-0.13.11.0/c2hs/toplevel/C2HSConfig.hs
@@ -24,7 +24,7 @@ --- TODO ---------------------------------------------
 --  Configuration options; largely set by `configure'.
 --
 --- TODO ----------------------------------------------------------------------
---  
+--
 module C2HSConfig (
   --
   -- programs and paths
@@ -70,8 +70,8 @@ cppopts  = case (os,cpp) of
 cppopts :: [String]
 cppopts  = case (os,cpp) of
   ("openbsd","cpp") -> ["-xc", "-w"]
-  (_,"cpp")         -> ["-x", "c", "-w"]
-  (_,"gcc")         -> ["-E", "-x", "c", "-w"]
+  (_,"cpp")         -> ["-x", "c", "-w", "-std=c99", "-D_Nullable=", "-D_Nonnull="]
+  (_,"gcc")         -> ["-E", "-x", "c", "-w", "-std=c99", "-D_Nullable=", "-D_Nonnull="]
   _                 -> []
 
 -- C preprocessor option for including only definitions (EXPORTED)
