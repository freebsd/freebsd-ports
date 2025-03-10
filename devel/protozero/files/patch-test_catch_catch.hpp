--- test/catch/catch.hpp.orig	2022-01-10 10:02:41 UTC
+++ test/catch/catch.hpp
@@ -175,8 +175,13 @@ namespace Catch {
 #    define CATCH_INTERNAL_SUPPRESS_UNUSED_WARNINGS \
          _Pragma( "clang diagnostic ignored \"-Wunused-variable\"" )
 
-#    define CATCH_INTERNAL_SUPPRESS_ZERO_VARIADIC_WARNINGS \
-         _Pragma( "clang diagnostic ignored \"-Wgnu-zero-variadic-macro-arguments\"" )
+#    if __clang_major__ >= 19
+#      define CATCH_INTERNAL_SUPPRESS_ZERO_VARIADIC_WARNINGS \
+           _Pragma( "clang diagnostic ignored \"-Wc++20-extensions\"" )
+#    else
+#      define CATCH_INTERNAL_SUPPRESS_ZERO_VARIADIC_WARNINGS \
+           _Pragma( "clang diagnostic ignored \"-Wgnu-zero-variadic-macro-arguments\"" )
+#endif
 
 #    define CATCH_INTERNAL_SUPPRESS_UNUSED_TEMPLATE_WARNINGS \
          _Pragma( "clang diagnostic ignored \"-Wunused-template\"" )
