--- src/corelib/global/qcompilerdetection.h.orig	2015-10-13 04:35:31 UTC
+++ src/corelib/global/qcompilerdetection.h
@@ -941,13 +941,26 @@
 #    undef Q_COMPILER_CONSTEXPR
 #  endif
 # endif // Q_OS_QNX
-# if (defined(Q_CC_CLANG) || defined(Q_CC_INTEL)) && defined(Q_OS_MAC) && defined(__GNUC_LIBSTD__) \
-    && ((__GNUC_LIBSTD__-0) * 100 + __GNUC_LIBSTD_MINOR__-0 <= 402)
+# if (defined(Q_CC_CLANG) || defined(Q_CC_INTEL)) && !defined(_LIBCPP_VERSION)
 // Apple has not updated libstdc++ since 2007, which means it does not have
 // <initializer_list> or std::move. Let's disable these features
+// The same applies to FreeBSD's base libstdc++ version used in FreeBSD 9.x.
 #  undef Q_COMPILER_INITIALIZER_LISTS
 #  undef Q_COMPILER_RVALUE_REFS
 #  undef Q_COMPILER_REF_QUALIFIERS
+// FreeBSD's base libstdc++ does not support std::u{16,32}string.
+#  undef Q_COMPILER_UNICODE_STRINGS
+// FreeBSD's base libstdc++ does not support std::declval, which is used in
+// together with noexcept in some headers such as qpair.h (as of Qt 5.5).
+// Since there is no macro checking for std::declval, just disable noexcept
+// altogether.
+#  undef Q_COMPILER_NOEXCEPT
+// FreeBSD's base libstdc++ is missing constexpr keywords on important
+// functions like std::numeric_limits<>::min(). Disable constexpr even if clang
+// advertises support for it.
+#  undef Q_COMPILER_CONSTEXPR
+// FreeBSD's base libstdc++ does not support std::nullptr_t.
+#  undef Q_COMPILER_NULLPTR
 // Also disable <atomic>, since it's clearly not there
 #  undef Q_COMPILER_ATOMICS
 # endif
