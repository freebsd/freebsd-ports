Fix warning which causes error in www/dooble due to -Werror being set.

/usr/local/include/qt6/QtCore/qspan.h:278:5: error: '__cpp_lib_span' is not defined, evaluates to 0

--- src/corelib/tools/qspan.h.orig	2024-01-22 10:20:09 UTC
+++ src/corelib/tools/qspan.h
@@ -275,7 +275,7 @@ class QSpanBase<T, q20::dynamic_extent> : protected QS
         : QSpanBase(other.data(), other.size())
     {}
 
-#if __cpp_lib_span
+#ifdef __cpp_lib_span
     template <typename S, size_t N, if_qualification_conversion<S> = true>
     Q_IMPLICIT constexpr QSpanBase(std::span<S, N> other) noexcept
         : QSpanBase(other.data(), other.size())
