--- src/Lib/optionmm/command_line.hpp.orig	2007-04-16 13:36:42 UTC
+++ src/Lib/optionmm/command_line.hpp
@@ -212,7 +212,13 @@ struct toggle_value<bool>
     {
         x = !x;
     }
-#if defined(__GNUC__) && __GNUC__ >= 2
+
+#if defined(__clang__)
+    inline void operator()(std::__bit_reference<std::vector<bool> > x)
+    {
+        x.flip();
+    }
+#elif defined(__GNUC__) && __GNUC__ >= 2
     inline void operator()(std::_Bit_reference x)
     {
         x.flip();
