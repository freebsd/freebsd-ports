--- src/libffwma/common.h.orig	2007-07-08 09:37:09.000000000 +0400
+++ src/libffwma/common.h	2007-07-08 09:37:26.000000000 +0400
@@ -65,14 +65,6 @@
 #define AVOPTION_SUB(ptr) { .name = NULL, .help = (const char*)ptr }
 #define AVOPTION_END() AVOPTION_SUB(NULL)
 
-struct AVOption;
-#ifdef HAVE_MMX
-extern const struct AVOption avoptions_common[3 + 5];
-#else
-extern const struct AVOption avoptions_common[3];
-#endif
-extern const struct AVOption avoptions_workaround_bug[11];
-
 #endif /* HAVE_AV_CONFIG_H */
 
 /* Suppress restrict if it was not defined in config.h.  */
