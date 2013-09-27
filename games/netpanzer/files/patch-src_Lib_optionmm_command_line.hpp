--- src/Lib/optionmm/command_line.hpp.orig	2013-09-27 10:31:25.000000000 +0200
+++ src/Lib/optionmm/command_line.hpp	2013-09-27 10:38:10.000000000 +0200
@@ -212,7 +212,13 @@
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
