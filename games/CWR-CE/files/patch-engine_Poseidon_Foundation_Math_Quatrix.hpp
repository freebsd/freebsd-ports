--- engine/Poseidon/Foundation/Math/Quatrix.hpp.orig	2026-08-04 10:46:28 UTC
+++ engine/Poseidon/Foundation/Math/Quatrix.hpp
@@ -1,9 +1,13 @@
 #pragma once
 
+#if defined(__aarch64__) || defined(__arm__)
+#include <sse2neon.h>
+#else
 #ifdef _MSC_VER
 #include <intrin.h>
 #else
 #include <xmmintrin.h>
+#endif
 #endif
 
 namespace Poseidon::Foundation
