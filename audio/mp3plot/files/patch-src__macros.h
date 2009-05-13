--- src/macros.h.orig	2009-04-14 11:21:18.000000000 +0900
+++ src/macros.h	2009-05-10 02:55:54.000000000 +0900
@@ -34,7 +34,7 @@
 // References of interest:
 // <http://sourcefrog.net/weblog/software/languages/C/unused.html>
 #ifndef UNUSED_
-#   ifdef __GNUC__
+#   if (defined(__GNUC__) && __GNUC__ > 3)
 #       define UNUSED_      __attribute__((unused))
 #       define DEPRECATED_  __attribute__((deprecated))
 #   // MSVC (_MSC_VER) doesn't seem to have an unused attribute (__declspec(...))
