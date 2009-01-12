--- src/ui.cpp.orig	2009-01-12 16:16:18.000000000 +0100
+++ src/ui.cpp	2009-01-12 16:16:26.000000000 +0100
@@ -21,7 +21,7 @@ extern "C" {
 #define M_LN10   2.3025850929940456840179914546843642
 #endif
 
-#define DBG(format, args...) fprintf(stderr, format, ## args)
+#define DBG(format, args...) //fprintf(stderr, format, ## args)
 
 void load_tag(ape_tag *tag, WavpackContext *ctx);
 void update_tag(ape_tag *tag, char *filename);
