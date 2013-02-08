--- ../../src/dmd/posix.mak.orig	2013-01-30 16:22:38.591086765 -0800
+++ ../../src/dmd/posix.mak	2013-01-30 16:23:37.631295903 -0800
@@ -49,7 +49,6 @@
 TK=tk
 ROOT=root
 
-MODEL=32
 ifneq (x,x$(MODEL))
     MODEL_FLAG=-m$(MODEL)
 endif
