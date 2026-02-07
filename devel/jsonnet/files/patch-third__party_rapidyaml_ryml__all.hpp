--- third_party/rapidyaml/ryml_all.hpp.orig	2025-07-26 11:37:10 UTC
+++ third_party/rapidyaml/ryml_all.hpp
@@ -20036,7 +20036,7 @@ constexpr const size_t char_traits< wchar_t >::num_whi
 #if defined(C4_POSIX) || defined(C4_IOS) || defined(C4_MACOS) || defined(C4_ARM)
 #   include <errno.h>
 #endif
-#if defined(C4_ARM)
+#if defined(C4_ARM) || defined(__FreeBSD__)
 #   include <malloc.h>
 #endif
 
@@ -21407,7 +21407,7 @@ RYML_EXPORT int version_patch();
 #endif /* C4_YML_EXPORT_HPP_ */
 
 
-#if defined(C4_MSVC) || defined(C4_MINGW)
+#if defined(C4_MSVC) || defined(C4_MINGW) || defined(__FreeBSD__)
 //included above:
 //#include <malloc.h>
 #else
