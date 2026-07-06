--- engine/Poseidon/Foundation/Math/V3QuadsP3.cpp.orig
+++ engine/Poseidon/Foundation/Math/V3QuadsP3.cpp
@@ -7,11 +7,15 @@
 #include <Poseidon/Foundation/Math/V3Quads.hpp>
 #include <Poseidon/Graphics/Core/TLVertex.hpp>
 #include <Poseidon/Foundation/Math/Math3D.hpp>
+#ifdef __aarch64__
+#include <sse2neon.h>
+#else
 #ifdef _MSC_VER
 #include <intrin.h> // For MMX intrinsics
 #else
 #include <x86intrin.h>
 #endif
+#endif

 #if defined __ICL
 #define _COMPILER_CAN_PIII 1
