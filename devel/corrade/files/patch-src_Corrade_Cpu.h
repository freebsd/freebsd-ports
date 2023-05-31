--- src/Corrade/Cpu.h.orig	2023-05-22 12:04:59 UTC
+++ src/Corrade/Cpu.h
@@ -1357,7 +1357,7 @@ equivalent:
 */
 template<class T> constexpr T tag() { return T{Implementation::Init}; }
 
-#if defined(CORRADE_TARGET_ARM) && defined(__linux__) && !(defined(CORRADE_TARGET_ANDROID) && __ANDROID_API__ < 18)
+#if defined(CORRADE_TARGET_ARM) && (defined(__linux__) && !(defined(CORRADE_TARGET_ANDROID) && __ANDROID_API__ < 18) || defined(__FreeBSD__))
 namespace Implementation {
     /* Needed for a friend declaration, implementation is at the very end of
        the header */
@@ -1496,7 +1496,7 @@ class Features {
         #endif
         Features runtimeFeatures();
         #endif
-        #if defined(CORRADE_TARGET_ARM) && defined(__linux__) && !(defined(CORRADE_TARGET_ANDROID) && __ANDROID_API__ < 18)
+        #if defined(CORRADE_TARGET_ARM) && (defined(__linux__) && !(defined(CORRADE_TARGET_ANDROID) && __ANDROID_API__ < 18) || defined(__FreeBSD__))
         friend Features Implementation::runtimeFeatures(unsigned long);
         #endif
 
@@ -1775,7 +1775,7 @@ value is equal to @ref Scalar, which in turn is equiva
 default-constructed) @ref Features.
 @see @ref DefaultBase, @ref DefaultExtra, @ref Default
 */
-#if (defined(CORRADE_TARGET_X86) && (defined(CORRADE_TARGET_MSVC) || defined(CORRADE_TARGET_GCC))) || (defined(CORRADE_TARGET_ARM) && ((defined(__linux__) && !(defined(CORRADE_TARGET_ANDROID) && __ANDROID_API__ < 18)) || defined(CORRADE_TARGET_APPLE))) || defined(DOXYGEN_GENERATING_OUTPUT)
+#if (defined(CORRADE_TARGET_X86) && (defined(CORRADE_TARGET_MSVC) || defined(CORRADE_TARGET_GCC))) || (defined(CORRADE_TARGET_ARM) && ((defined(__linux__) && !(defined(CORRADE_TARGET_ANDROID) && __ANDROID_API__ < 18)) || defined(CORRADE_TARGET_APPLE) || defined(__FreeBSD__))) || defined(DOXYGEN_GENERATING_OUTPUT)
 #ifdef CORRADE_TARGET_ARM
 CORRADE_UTILITY_EXPORT /* Inlined on x86 at the very end of the header */
 #endif
@@ -3214,7 +3214,7 @@ inline Features runtimeFeatures() {
 /** @todo If AT_HWCAP2 or other bits are needed, it's passed to ifunc resolvers
     only since glibc 2.30 (and Android API 30+, which is the same as before):
     https://github.com/bminor/glibc/commit/2b8a3c86e7606cf1b0a997dad8af2d45ae8989c3 */
-#if defined(CORRADE_TARGET_ARM) && defined(__linux__) && !(defined(CORRADE_TARGET_ANDROID) && __ANDROID_API__ < 18)
+#if defined(CORRADE_TARGET_ARM) && (defined(__linux__) && !(defined(CORRADE_TARGET_ANDROID) && __ANDROID_API__ < 18) || defined(__FreeBSD__))
 namespace Implementation {
     inline Features runtimeFeatures(const unsigned long caps) {
         unsigned int out = 0;
