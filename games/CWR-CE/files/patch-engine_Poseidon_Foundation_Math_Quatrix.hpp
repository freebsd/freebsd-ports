--- engine/Poseidon/Foundation/Math/Quatrix.hpp.orig
+++ engine/Poseidon/Foundation/Math/Quatrix.hpp
@@ -1,10 +1,14 @@
 #pragma once

+#ifdef __aarch64__
+#include <sse2neon.h>
+#else
 #ifdef _MSC_VER
 #include <intrin.h>
 #else
 #include <xmmintrin.h>
 #endif
+#endif

 namespace Poseidon::Foundation
 {
