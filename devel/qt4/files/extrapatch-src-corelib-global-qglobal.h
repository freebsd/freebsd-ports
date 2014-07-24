commit bc620055c82a8ccae49144ad99bf9226d659f852
Author: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date:   Sun Jul 13 23:15:00 2014 +0300

    Move the C++11 support macros to a central place.
    
    The main objective of this commit is to make C++11 support work with
    clang: so far, the Q_COMPILER_* definitions related to C++11 were
    enabled based on __GNUC__ and __GNUC_MINOR__; while clang does define
    those two, __GNUC_MINOR__ is hardcoded at "2" and thus none of the
    macros end up being defined.
    
    We now make qglobal.h more similar to how qtbase's qcompilerdetection.h
    works by separating the detection of the C++11 features supported by a
    compiler from the detection of the compilers themselves.
    
    It is important to note the list of macros has not changed, the macros
    have only been moved.
    
    This commit either follows the spirit of or is a cherry-pick of the
    following qtbase ones:
    - 4131c323a36ee8680a3b4d66a2a03a00544751c2 (Update the C++11 support
      macros)
    - 8dd66f42e834320c4ba0a6f2e45855d591b3b6e7 (Avoid undefined macro
      warning for __GXX_EXPERIMENTAL_CXX0X__)
    - fe5d5fdaf1d9b7d108727d290e24a6b0f00139c6 (clang: Use __has_feature()
      to detect C++11 features)
    - 0ec953c93688ec0de74cda43b91f66f4cf879e5f (Remove extra Q_COMPILER_xxx
      defines from the MSVC section)
    - 163dcf2b71f34a12137f200e4af5640e42e5f5e2 (Fix build with older Clang
      versions without __has_extension)
    - 53262b9b5b9cb536916f6d6e086a944cb17bb8d8 (Only define the MSVC C++11
      feature macros in C++)
    
    Change-Id: I2ca35af1a23260a9373943f97a8a72db3fc670e4
    Reviewed-by: Thiago Macieira <thiago.macieira@intel.com>

diff --git a/src/corelib/global/qglobal.h b/src/corelib/global/qglobal.h
index 158ef78..4f1384b 100644
--- src/corelib/global/qglobal.h
+++ src/corelib/global/qglobal.h
@@ -463,17 +463,6 @@ namespace QT_NAMESPACE {}
 #    undef QT_HAVE_3DNOW
 #  endif
 
-#if defined(Q_CC_MSVC) && _MSC_VER >= 1600
-#      define Q_COMPILER_RVALUE_REFS
-#      define Q_COMPILER_AUTO_FUNCTION
-#      define Q_COMPILER_AUTO_TYPE
-#      define Q_COMPILER_LAMBDA
-#      define Q_COMPILER_DECLTYPE
-//  MSCV has std::initilizer_list, but do not support the braces initialization
-//#      define Q_COMPILER_INITIALIZER_LISTS
-#  endif
-
-
 #elif defined(__BORLANDC__) || defined(__TURBOC__)
 #  define Q_CC_BOR
 #  define Q_INLINE_TEMPLATE
@@ -505,6 +494,7 @@ namespace QT_NAMESPACE {}
 /* work-around for missing compiler intrinsics */
 #  define __is_empty(X) false
 #  define __is_pod(X) false
+
 #elif defined(__GNUC__)
 #  define Q_CC_GNU
 #  define Q_C_CALLBACKS
@@ -518,6 +508,10 @@ namespace QT_NAMESPACE {}
 #  if defined(__clang__)
 /* Clang also masquerades as GCC 4.2.1 */
 #    define Q_CC_CLANG
+#    if !defined(__has_extension)
+#      /* Compatibility with older Clang versions */
+#      define __has_extension __has_feature
+#    endif
 #  endif
 #  ifdef __APPLE__
 #    define Q_NO_DEPRECATED_CONSTRUCTORS
@@ -558,33 +552,6 @@ namespace QT_NAMESPACE {}
 #      define QT_NO_ARM_EABI
 #    endif
 #  endif
-#  if defined(__GXX_EXPERIMENTAL_CXX0X__)
-#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 403
-       /* C++0x features supported in GCC 4.3: */
-#      define Q_COMPILER_RVALUE_REFS
-#      define Q_COMPILER_DECLTYPE
-#    endif
-#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404
-       /* C++0x features supported in GCC 4.4: */
-#      define Q_COMPILER_VARIADIC_TEMPLATES
-#      define Q_COMPILER_AUTO_FUNCTION
-#      define Q_COMPILER_AUTO_TYPE
-#      define Q_COMPILER_EXTERN_TEMPLATES
-#      define Q_COMPILER_DEFAULT_DELETE_MEMBERS
-#      define Q_COMPILER_CLASS_ENUM
-#      define Q_COMPILER_INITIALIZER_LISTS
-#    endif
-#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 405
-       /* C++0x features supported in GCC 4.5: */
-#      define Q_COMPILER_LAMBDA
-#      define Q_COMPILER_UNICODE_STRINGS
-#    endif
-#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406
-       /* C++0x features supported in GCC 4.6: */
-#      define Q_COMPILER_CONSTEXPR
-#    endif
-
-#  endif
 
 /* IBM compiler versions are a bit messy. There are actually two products:
    the C product, and the C++ product. The C++ compiler is always packaged
@@ -829,12 +796,33 @@ namespace QT_NAMESPACE {}
 #  error "Qt has not been tested with this compiler - talk to qt-bugs@trolltech.com"
 #endif
 
+/*
+ * C++11 support
+ *
+ *  Paper           Macro                               SD-6 macro
+ *  N2541           Q_COMPILER_AUTO_FUNCTION
+ *  N1984 N2546     Q_COMPILER_AUTO_TYPE
+ *  N2437           Q_COMPILER_CLASS_ENUM
+ *  N2235           Q_COMPILER_CONSTEXPR                __cpp_constexpr = 200704
+ *  N2343 N3276     Q_COMPILER_DECLTYPE                 __cpp_decltype = 200707
+ *  N2346           Q_COMPILER_DEFAULT_DELETE_MEMBERS
+ *  N1987           Q_COMPILER_EXTERN_TEMPLATES
+ *  N2672           Q_COMPILER_INITIALIZER_LISTS
+ *  N2658 N2927     Q_COMPILER_LAMBDA                   __cpp_lambdas = 200907
+ *  N2118 N2844 N3053 Q_COMPILER_RVALUE_REFS            __cpp_rvalue_references = 200610
+ *  N2442           Q_COMPILER_UNICODE_STRINGS          __cpp_unicode_literals = 200710
+ *  N2242 N2555     Q_COMPILER_VARIADIC_TEMPLATES       __cpp_variadic_templates = 200704
+ *
+ * For any future version of the C++ standard, we use only the SD-6 macro.
+ * For full listing, see
+ *  http://isocpp.org/std/standing-documents/sd-6-sg10-feature-test-recommendations
+ */
 
 #ifdef Q_CC_INTEL
 #  if __INTEL_COMPILER < 1200
 #    define Q_NO_TEMPLATE_FRIENDS
 #  endif
-#  if defined(__GXX_EXPERIMENTAL_CXX0X__) || defined(__GXX_EXPERIMENTAL_CPP0X__)
+#  if __cplusplus >= 201103L
 #    if __INTEL_COMPILER >= 1100
 #      define Q_COMPILER_RVALUE_REFS
 #      define Q_COMPILER_EXTERN_TEMPLATES
@@ -849,6 +837,91 @@ namespace QT_NAMESPACE {}
 #  endif
 #endif
 
+#if defined(Q_CC_CLANG) && !defined(Q_CC_INTEL)
+#  if __cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__)
+    /* Detect C++ features using __has_feature(), see http://clang.llvm.org/docs/LanguageExtensions.html#cxx11 */
+#    if __has_feature(cxx_auto_type)
+#      define Q_COMPILER_AUTO_FUNCTION
+#      define Q_COMPILER_AUTO_TYPE
+#    endif
+#    if __has_feature(cxx_constexpr)
+#      define Q_COMPILER_CONSTEXPR
+#    endif
+#    if __has_feature(cxx_decltype) /* && __has_feature(cxx_decltype_incomplete_return_types) */
+#      define Q_COMPILER_DECLTYPE
+#    endif
+#    if __has_feature(cxx_defaulted_functions) && __has_feature(cxx_deleted_functions)
+#      define Q_COMPILER_DEFAULT_DELETE_MEMBERS
+#    endif
+#    if __has_feature(cxx_generalized_initializers)
+#      define Q_COMPILER_INITIALIZER_LISTS
+#    endif
+#    if __has_feature(cxx_lambdas)
+#      define Q_COMPILER_LAMBDA
+#    endif
+#    if __has_feature(cxx_rvalue_references)
+#      define Q_COMPILER_RVALUE_REFS
+#    endif
+#    if __has_feature(cxx_strong_enums)
+#      define Q_COMPILER_CLASS_ENUM
+#    endif
+#    if __has_feature(cxx_unicode_literals)
+#      define Q_COMPILER_UNICODE_STRINGS
+#    endif
+#    if __has_feature(cxx_variadic_templates)
+#      define Q_COMPILER_VARIADIC_TEMPLATES
+#    endif
+    /* Features that have no __has_feature() check */
+#    if ((__clang_major__ * 100) + __clang_minor__) >= 209 /* since clang 2.9 */
+#      define Q_COMPILER_EXTERN_TEMPLATES
+#    endif
+#  endif
+#endif
+
+#if defined(Q_CC_GNU) && !defined(Q_CC_INTEL) && !defined(Q_CC_CLANG)
+#  if defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L
+#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 403
+       /* C++0x features supported in GCC 4.3: */
+#      define Q_COMPILER_RVALUE_REFS
+#      define Q_COMPILER_DECLTYPE
+#    endif
+#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404
+       /* C++0x features supported in GCC 4.4: */
+#      define Q_COMPILER_VARIADIC_TEMPLATES
+#      define Q_COMPILER_AUTO_FUNCTION
+#      define Q_COMPILER_AUTO_TYPE
+#      define Q_COMPILER_EXTERN_TEMPLATES
+#      define Q_COMPILER_DEFAULT_DELETE_MEMBERS
+#      define Q_COMPILER_CLASS_ENUM
+#      define Q_COMPILER_INITIALIZER_LISTS
+#    endif
+#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 405
+       /* C++0x features supported in GCC 4.5: */
+#      define Q_COMPILER_LAMBDA
+#      define Q_COMPILER_UNICODE_STRINGS
+#    endif
+#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406
+       /* C++0x features supported in GCC 4.6: */
+#      define Q_COMPILER_CONSTEXPR
+#    endif
+#  endif
+#endif
+
+#if defined(Q_CC_MSVC) && !defined(Q_CC_INTEL)
+#  if defined(__cplusplus)
+#    if _MSC_VER >= 1600
+       /* C++11 features supported in VC10 = VC2010: */
+#      define Q_COMPILER_AUTO_FUNCTION
+#      define Q_COMPILER_AUTO_TYPE
+#      define Q_COMPILER_DECLTYPE
+#      define Q_COMPILER_LAMBDA
+#      define Q_COMPILER_RVALUE_REFS
+//  MSVC's library has std::initializer_list, but the compiler does not support the braces initialization
+//#      define Q_COMPILER_INITIALIZER_LISTS
+#    endif
+#  endif
+#endif
+
 #ifndef Q_PACKED
 #  define Q_PACKED
 #  undef Q_NO_PACKED_REFERENCE
