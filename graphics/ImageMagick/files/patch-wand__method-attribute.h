--- wand/method-attribute.h.orig	2014-06-18 15:21:47.000000000 +0200
+++ wand/method-attribute.h	2014-12-19 17:09:14.000000000 +0100
@@ -116,14 +116,18 @@ extern "C" {
 #  define wand_unreferenced(x)  /* nothing */
 #endif
 
-#if (defined(__clang__) || (((__GNUC__) > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 3)))) && !defined(__apple_build_version__)
+#if !defined(__clang__) && (((__GNUC__) > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 3)))
 #  define wand_alloc_size(x)  __attribute__((__alloc_size__(x)))
 #  define wand_alloc_sizes(x,y)  __attribute__((__alloc_size__(x,y)))
-#  define wand_cold_spot  __attribute__((__cold__))
-#  define wand_hot_spot  __attribute__((__hot__))
 #else
 #  define wand_alloc_size(x)  /* nothing */
 #  define wand_alloc_sizes(x,y)  /* nothing */
+#endif
+
+#if defined(__clang__) || (((__GNUC__) > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 3)))
+#  define wand_cold_spot  __attribute__((__cold__))
+#  define wand_hot_spot  __attribute__((__hot__))
+#else
 #  define wand_cold_spot
 #  define wand_hot_spot
 #endif
