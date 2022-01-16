--- external/libromfs/generator/include/embedder.hpp.orig	2022-01-16 07:27:44 UTC
+++ external/libromfs/generator/include/embedder.hpp
@@ -5,13 +5,13 @@ R"embedder(
 
     #define RESOURCE(name, path)                        \
     __asm__ (                                           \
-        ".global _" #name "\n"                          \
-        ".global _" #name "_size\n"                     \
-        "_" #name ":\n"                                 \
+        ".global " #name "\n"                          \
+        ".global " #name "_size\n"                     \
+        #name ":\n"                                 \
             ".incbin \"" path "\"\n"                    \
             ".align 8\n"                                \
-        "_" #name "_size:\n"                            \
-            ".int _" #name "_size - _" #name " - 1\n"   \
+        #name "_size:\n"                            \
+            ".int " #name "_size - " #name " - 1\n"   \
             ".align 8\n"                                \
     )
 
