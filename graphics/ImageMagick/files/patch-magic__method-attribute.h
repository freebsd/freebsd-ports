--- magick/method-attribute.h.orig	2014-03-21 19:28:48.000000000 +0100
+++ magick/method-attribute.h	2014-12-19 17:09:11.000000000 +0100
@@ -123,14 +123,18 @@ extern "C" {
 #  define magick_unreferenced(x)  /* nothing */
 #endif
 
-#if (defined(__clang__) || (((__GNUC__) > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 3)))) && !defined(__apple_build_version__)
+#if !defined(__clang__) && (((__GNUC__) > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 3)))
 #  define magick_alloc_size(x)  __attribute__((__alloc_size__(x)))
 #  define magick_alloc_sizes(x,y)  __attribute__((__alloc_size__(x,y)))
-#  define magick_cold_spot  __attribute__((__cold__))
-#  define magick_hot_spot  __attribute__((__hot__))
 #else
 #  define magick_alloc_size(x)  /* nothing */
 #  define magick_alloc_sizes(x,y)  /* nothing */
+#endif
+
+#if defined(__clang__) || (((__GNUC__) > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 3)))
+#  define magick_cold_spot  __attribute__((__cold__))
+#  define magick_hot_spot  __attribute__((__hot__))
+#else
 #  define magick_cold_spot
 #  define magick_hot_spot
 #endif
