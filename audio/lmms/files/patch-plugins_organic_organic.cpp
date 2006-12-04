--- plugins/organic/organic.cpp.orig	Mon Dec  4 15:22:23 2006
+++ plugins/organic/organic.cpp	Mon Dec  4 16:02:07 2006
@@ -64,6 +64,7 @@
 #include "embed.cpp"
 #include "volume_knob.h"
 
+#define log2f(x) (logf((x)) / logf(2))
 
 extern "C"
 {
