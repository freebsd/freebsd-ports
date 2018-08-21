--- libheif/encoder_fuzzer.cc.orig	2018-06-19 09:35:37 UTC
+++ libheif/encoder_fuzzer.cc
@@ -20,6 +20,7 @@
 
 #include <assert.h>
 #include <string.h>
+#include <stdlib.h>
 
 #include <memory>
 
