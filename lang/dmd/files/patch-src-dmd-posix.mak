--- ../../src/dmd/posix.mak.orig	2012-12-31 12:16:46.000000000 -0800
+++ ../../src/dmd/posix.mak	2013-01-30 16:20:15.160587655 -0800
@@ -49,7 +49,6 @@
 TK=tk
 ROOT=root
 
-MODEL=32
 ifneq (x,x$(MODEL))
     MODEL_FLAG=-m$(MODEL)
 endif
