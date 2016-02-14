clang: Only enable Q_COMPILER_INITIALIZER_LISTS with libc++.

This is a workaround for the FreeBSD 9.x series: in Qt 4.8.7, C++11 features
are detected by checking if the compiler supports them. However, initializer
lists support also depends on the C++ standard library. 9.x's libstdc++ from
base (GCC 4.2) does not, so ports with e.g. USES=compiler:c++0x or
compiler:c++11-lang would break: they build with clang and base's libstdc++, so
Qt considers the support is there (including the C++ header) while this is not
the case.

Work around the problem by only enabling Q_COMPILER_INITIALIZER_LISTS if libc++
is being used. Detecting libstdc++'s version is too cumbersome (we would at
least need to include a non-lightweight header such as cstdio to have access to
__GLIBCXX__) and not worth the effort.
--- src/corelib/global/qglobal.h
+++ src/corelib/global/qglobal.h
@@ -854,7 +855,18 @@ namespace QT_NAMESPACE {}
 #      define Q_COMPILER_DEFAULT_DELETE_MEMBERS
 #    endif
 #    if __has_feature(cxx_generalized_initializers)
-#      define Q_COMPILER_INITIALIZER_LISTS
+/*
+ * Workaround for FreeBSD 9.x, where we can end up building a port with clang
+ * and base's libstdc++ from GCC 4.2 (which does not support initializer
+ * lists). Since detecting libstdc++'s version is not trivial, only enable the
+ * macro with libc++.
+ */
+#      if defined(__cplusplus)  /* Only C++ has ciso646. */
+#        include <ciso646>
+#        if defined(_LIBCPP_VERSION)
+#          define Q_COMPILER_INITIALIZER_LISTS
+#        endif
+#      endif
 #    endif
 #    if __has_feature(cxx_lambdas)
 #      define Q_COMPILER_LAMBDA
