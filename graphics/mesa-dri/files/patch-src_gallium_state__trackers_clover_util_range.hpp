From b95533b981af9a6687b41418e7cc2a5652fc2bdb Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Jean-S=C3=A9bastien=20P=C3=A9dron?= <dumbbell@FreeBSD.org>
Date: Fri, 7 Mar 2014 15:16:08 +0100
Subject: [PATCH 3/3] Work around for clang 3.4 which fails to build Clover

See:
  https://bugs.freedesktop.org/show_bug.cgi?id=74098#c3
--- src/gallium/state_trackers/clover/util/range.hpp.orig	2016-11-10 22:05:17 UTC
+++ src/gallium/state_trackers/clover/util/range.hpp
@@ -362,6 +362,12 @@ namespace clover {
       return { i, i + n };
    }
 
+   namespace detail {
+      template<typename T>
+      using fixup_function_type =
+         typename std::conditional<std::is_function<T>::value, T &, T>::type;
+   }
+
    ///
    /// Create a range by transforming the contents of a number of
    /// source ranges \a rs element-wise using a provided functor \a f.
@@ -369,7 +375,7 @@ namespace clover {
    /// \sa adaptor_range.
    ///
    template<typename F, typename... Rs>
-   adaptor_range<F, Rs...>
+   adaptor_range<detail::fixup_function_type<F>, Rs...>
    map(F &&f, Rs &&... rs) {
       return { std::forward<F>(f), std::forward<Rs>(rs)... };
    }
