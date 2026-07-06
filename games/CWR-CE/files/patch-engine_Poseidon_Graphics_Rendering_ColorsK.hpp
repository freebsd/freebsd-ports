--- engine/Poseidon/Graphics/Rendering/ColorsK.hpp.orig
+++ engine/Poseidon/Graphics/Rendering/ColorsK.hpp
@@ -2,7 +2,11 @@
 int toInt(float fval);
 int toInt(double f);

+#ifdef __aarch64__
+#include <sse2neon.h>
+#else
 #include <xmmintrin.h>
+#endif
 #include <Poseidon/Foundation/platform.hpp>
 #include <Poseidon/Foundation/Math/MathDefs.hpp>

