--- engine/Poseidon/Graphics/Rendering/ColorsK.hpp.orig	2026-08-04 10:46:27 UTC
+++ engine/Poseidon/Graphics/Rendering/ColorsK.hpp
@@ -2,7 +2,11 @@ int toInt(double f);
 int toInt(float fval);
 int toInt(double f);
 
+#if defined(__aarch64__) || defined(__arm__)
+#include <sse2neon.h>
+#else
 #include <xmmintrin.h>
+#endif
 #include <Poseidon/Foundation/platform.hpp>
 #include <Poseidon/Foundation/Math/MathDefs.hpp>
 
