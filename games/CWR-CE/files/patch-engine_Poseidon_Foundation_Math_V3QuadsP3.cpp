--- engine/Poseidon/Foundation/Math/V3QuadsP3.cpp.orig	2026-08-04 10:46:28 UTC
+++ engine/Poseidon/Foundation/Math/V3QuadsP3.cpp
@@ -7,10 +7,14 @@
 #include <Poseidon/Foundation/Math/V3Quads.hpp>
 #include <Poseidon/Graphics/Core/TLVertex.hpp>
 #include <Poseidon/Foundation/Math/Math3D.hpp>
+#if defined(__aarch64__) || defined(__arm__)
+#include <sse2neon.h>
+#else
 #ifdef _MSC_VER
 #include <intrin.h> // For MMX intrinsics
 #else
 #include <x86intrin.h>
+#endif
 #endif
 
 #if defined __ICL
