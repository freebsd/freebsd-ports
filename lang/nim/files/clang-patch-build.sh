--- config/nim.cfg.orig 2020-04-03 17:22:53 UTC
+++ config/nim.cfg
@@ -8,7 +8,7 @@
 # Environment variables can be accessed like so:
 #  gcc.path %= "$CC_PATH"
 
-cc = gcc
+cc = clang
 
 # additional options always passed to the compiler:
 --parallel_build: "0" # 0 to auto-detect number of processors
