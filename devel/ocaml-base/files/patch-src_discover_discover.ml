--- src/discover/discover.ml.orig	2024-04-29 15:54:18 UTC
+++ src/discover/discover.ml
@@ -4,7 +4,11 @@ int main(int argc, char ** argv)
   {|
 int main(int argc, char ** argv)
 {
+#if defined(__clang__) && !defined(__x86_64__) && !defined(__i386__)
+#error "-mpopcnt is not for this arch"
+#else
   return __builtin_popcount(argc);
+#endif
 }
 |}
 ;;
