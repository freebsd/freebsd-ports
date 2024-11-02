Fix build with LLVM >= 19.1.0-rc1.

Clang >= 19.1.0-rc1 enables C++17 relaxed template template argument
matching by default. The workaround in qtcreator before this was the
case is now causing build failures.

--- src/libs/utils/algorithm.h.orig	2024-09-27 01:17:49 UTC
+++ src/libs/utils/algorithm.h
@@ -258,7 +258,7 @@ Q_REQUIRED_RESULT decltype(auto) transform(SC &&contai
          typename Result = std::decay_t<std::invoke_result_t<F, Value&>>,
          typename ResultContainer = C<Result>>
 Q_REQUIRED_RESULT decltype(auto) transform(SC &&container, F function);
-#ifdef Q_CC_CLANG
+#if defined(Q_CC_CLANG) && !defined(__cpp_template_template_args)
 // "Matching of template template-arguments excludes compatible templates"
 // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0522r0.html (P0522R0)
 // in C++17 makes the above match e.g. C=std::vector even though that takes two
@@ -809,7 +809,7 @@ Q_REQUIRED_RESULT decltype(auto) transform(SC &&contai
     return transform<ResultContainer>(std::forward<SC>(container), function);
 }
 
-#ifdef Q_CC_CLANG
+#if defined(Q_CC_CLANG) && !defined(__cpp_template_template_args)
 template<template<typename, typename> class C, // result container type
          typename SC,                          // input container type
          typename F,                           // function type
