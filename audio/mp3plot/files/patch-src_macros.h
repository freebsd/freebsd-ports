--- src/macros.h.orig	2009-04-14 02:21:18 UTC
+++ src/macros.h
@@ -34,7 +34,7 @@
 // References of interest:
 // <http://sourcefrog.net/weblog/software/languages/C/unused.html>
 #ifndef UNUSED_
-#   ifdef __GNUC__
+#   if (defined(__GNUC__) && __GNUC__ > 3)
 #       define UNUSED_      __attribute__((unused))
 #       define DEPRECATED_  __attribute__((deprecated))
 #   // MSVC (_MSC_VER) doesn't seem to have an unused attribute (__declspec(...))
