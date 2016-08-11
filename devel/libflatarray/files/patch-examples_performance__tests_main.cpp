--- examples/performance_tests/main.cpp.orig	2016-02-02 20:14:50 UTC
+++ examples/performance_tests/main.cpp
@@ -10,7 +10,14 @@
 #include <libflatarray/short_vec.hpp>
 #include <libflatarray/testbed/cpu_benchmark.hpp>
 #include <libflatarray/testbed/evaluate.hpp>
+
+#ifdef __SSE__
+#include <xmmintrin.h>
+#endif
+
+#ifdef __AVX__
 #include <immintrin.h>
+#endif
 
 #define WEIGHT_S 0.11
 #define WEIGHT_T 0.12
@@ -118,6 +125,7 @@ private:
     }
 };
 
+#ifdef __SSE__
 class JacobiD3Q7Pepper : public JacobiD3Q7
 {
 public:
@@ -292,6 +300,7 @@ private:
         }
     }
 };
+#endif
 
 class JacobiCell
 {
@@ -416,6 +425,7 @@ private:
     }
 };
 
+#ifdef __SSE__
 class JacobiD3Q7Silver : public JacobiD3Q7
 {
 public:
@@ -634,6 +644,7 @@ private:
         }
     }
 };
+#endif
 
 class Particle
 {
@@ -1477,7 +1488,7 @@ int main(int argc, char **argv)
         eval(JacobiD3Q7Vanilla(), *i);
     }
 
-#ifdef __AVX__
+#ifdef __SSE__
     for (std::vector<std::vector<int> >::iterator i = sizes.begin(); i != sizes.end(); ++i) {
         eval(JacobiD3Q7Pepper(), *i);
     }
@@ -1487,9 +1498,11 @@ int main(int argc, char **argv)
         eval(JacobiD3Q7Bronze(), *i);
     }
 
+#ifdef __SSE__
     for (std::vector<std::vector<int> >::iterator i = sizes.begin(); i != sizes.end(); ++i) {
         eval(JacobiD3Q7Silver(), *i);
     }
+#endif
 
     sizes.clear();
 
