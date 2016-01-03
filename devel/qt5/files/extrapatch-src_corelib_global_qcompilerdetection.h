--- src/corelib/global/qcompilerdetection.h.orig	2016-01-03 18:13:55 UTC
+++ src/corelib/global/qcompilerdetection.h
@@ -900,10 +900,10 @@
 #    undef Q_COMPILER_REF_QUALIFIERS
 #  endif
 # endif // Q_OS_QNX
-# if (defined(Q_CC_CLANG) || defined(Q_CC_INTEL)) && defined(Q_OS_MAC) && defined(__GNUC_LIBSTD__) \
-    && ((__GNUC_LIBSTD__-0) * 100 + __GNUC_LIBSTD_MINOR__-0 <= 402)
+# if (defined(Q_CC_CLANG) || defined(Q_CC_INTEL)) && !defined(_LIBCPP_VERSION)
 // Mac OS X: Apple has not updated libstdc++ since 2007, which means it does not have
 // <initializer_list> or std::move. Let's disable these features
+// The same applies to FreeBSD's base libstdc++ version used in FreeBSD 9.x.
 #  undef Q_COMPILER_INITIALIZER_LISTS
 #  undef Q_COMPILER_RVALUE_REFS
 #  undef Q_COMPILER_REF_QUALIFIERS
