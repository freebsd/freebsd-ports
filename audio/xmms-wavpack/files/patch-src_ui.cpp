--- src/ui.cpp.orig	2009-09-28 02:52:56 UTC
+++ src/ui.cpp
@@ -21,7 +21,7 @@ extern "C" {
 #define M_LN10   2.3025850929940456840179914546843642
 #endif
 
-#define DBG(format, args...) fprintf(stderr, format, ## args)
+#define DBG(format, args...) //fprintf(stderr, format, ## args)
 
 void load_tag(ape_tag *tag, WavpackContext *ctx);
 void update_tag(ape_tag *tag, char *filename);
