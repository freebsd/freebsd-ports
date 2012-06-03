--- ./compiler/main/DriverPipeline.hs.orig	2012-05-17 11:27:22.763461303 +0200
+++ ./compiler/main/DriverPipeline.hs	2012-05-17 11:27:00.427463463 +0200
@@ -1753,6 +1753,14 @@
                           then ["-Wl,-no_compact_unwind"]
                           else [])
 
+                      ++ (if cLdHashSize31 == "YES"
+                          then ["-Wl,--hash-size=31"]
+                          else [])
+
+                      ++ (if cLdReduceMemoryOverheads == "YES"
+                          then ["-Wl,--reduce-memory-overheads"]
+                          else [])
+
                       -- '-Wl,-read_only_relocs,suppress'
                       -- ld gives loads of warnings like:
                       --     ld: warning: text reloc in _base_GHCziArr_unsafeArray_info to _base_GHCziArr_unsafeArray_closure
